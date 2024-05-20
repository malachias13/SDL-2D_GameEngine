#include <GL/glew.h>
#include "Game.h"
#include "Actor.h"
#include "Renderer/VertexArray.h"
#include "Renderer/Shader.h"
#include "Renderer/Texture.h"
#include "Components/SpriteComponent.h"
#include "Components/BGSpriteComponent.h"

Game::Game() :
    mWindow(nullptr),
    mIsRunning(true)
{
}

bool Game::Initialize()
{
    flags = IMG_INIT_JPG | IMG_INIT_PNG;
    int sdlResult = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    if (sdlResult != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }
    
    // init image
    int initted = IMG_Init(flags);
    if ((initted & flags) != flags) {
        printf("IMG_Init: Failed to init required jpg and png support!\n");
        printf("IMG_Init: %s\n", IMG_GetError());
        // handle error
    }

    // Use the core OpenGL profile
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    // Request a color buffer with 8-bits per RGBA channel
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    // Enable double buffering
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    // Force OpenGL to use hardware acceleration
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

    // Creating the window
   // flags += SDL_WINDOW_FULLSCREEN_DESKTOP;
   // flags += SDL_WINDOW_OPENGL;
    mWindow = SDL_CreateWindow("2D Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        mWindowSize[0], mWindowSize[1], SDL_WINDOW_OPENGL);
    if (!mWindow) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }

    mContext = SDL_GL_CreateContext(mWindow);

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        SDL_Log("Failed to initialize GLEW.");
        return false;
    }   
    glGetError();

    if (!LoadShaders())
    {
        SDL_Log("Failed to load shaders.");
        return false;
    }

    CreateSpriteVerts();

    BeginPlay();

    mTicksCount = SDL_GetTicks();

    return true;
}

void Game::RunLoop()
{
    while (mIsRunning)
    {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::Shutdown()
{
    EndPlay();
    IMG_Quit();
    delete mSpriteVerts;
    mSpriteShader->Unload();
    delete mSpriteShader;

    SDL_GL_DeleteContext(mContext);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Game::ProcessInput()
{
    SDL_Event event;
    // While there are still events in the queue
    while(SDL_PollEvent(&event)) {
        switch (event.type)
        {
        case SDL_QUIT:
            mIsRunning = false;
            break;
        }
    }

    // Get state of keyboard.
    // Using the escape key to close the window.
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_ESCAPE]) {
        mIsRunning = false;
    }
    if (state[SDL_SCANCODE_F11]) {
        FullScreenToggle();
    }

    mUpdatingActors = true;
    for (auto actor : mActors)
    {
        actor->ProcessInput(state);
    }
    mUpdatingActors = false;
}

void Game::UpdateGame()
{
    // wailt until 16ms has elapsed since last frame (Cape the frame rate at 60FPS)
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));

    /* Delta time is the difference in ticks from last frame
     (converted to seconds) */
    mDeltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
    // clamp maximum delta time value
    if (mDeltaTime > 0.05f)
    {
        mDeltaTime = 0.05f;
    }
    mTicksCount = SDL_GetTicks();

    // Updating all actors
    mUpdatingActors = true;

    for (auto actor : mActors) {
        actor->Update(mDeltaTime);
    }
    mUpdatingActors = false;

    // Move pending actors to mActors
    for (auto pending : mPendingActors) {
        pending->ComputeWorldTransform();
        mActors.emplace_back(pending);
    }
    mPendingActors.clear();

    // Add any dead actor to a temp vector
    std::vector<Actor*> deadActors;
    for (auto actor : mActors) {
        if (actor->GetState() == Actor::EDead)
        {
            deadActors.emplace_back(actor);
        }
    }

    for (auto actor : deadActors) {
        delete actor;
    }



}

void Game::GenerateOutput()
{
    // Clearing the back buffer to a color
    glClearColor(0.86f, 0.86f, 0.86f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Enable alpha blending on the color buffer
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Set sprite shader and vertex array objects active
    mSpriteShader->SetActive();
    mSpriteVerts->SetActive();

    // Draw all sprite components
    for (auto sprite : mSprites)
    {
        sprite->Draw(mSpriteShader);
    }

    // Swap front buffer and back buffer
    SDL_GL_SwapWindow(mWindow);
}

void Game::CreateSpriteVerts()
{
    float vertices[] = {
       -0.5f,  0.5f, 0.f, 0.f, 0.f, // top left
        0.5f,  0.5f, 0.f, 1.f, 0.f, // top right
        0.5f, -0.5f, 0.f, 1.f, 1.f, // bottom right
       -0.5f, -0.5f, 0.f, 0.f, 1.f  // bottom left
    };
    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    mSpriteVerts = new VertexArray(vertices, 4, indices, 6);
}

bool Game::LoadShaders()
{
    mSpriteShader = new Shader();
    if (!mSpriteShader->Load("Shaders/Sprite.vert", "Shaders/Sprite.frag"))
    {
        return false;
    }
    mSpriteShader->SetActive();
    Matrix4 viewProj = Matrix4::CreateSimpleViewProj(mWindowSize[0], mWindowSize[1]);
    mSpriteShader->SetMatrixUniform("uViewProj", viewProj);
    
    return true;
}

Texture* Game::GetTexture(const std::string& fileName)
{
    Texture* tex = nullptr;
    auto iter = mTextures.find(fileName);
    if (iter != mTextures.end())
    {
        tex = iter->second;
    }
    else
    {
        tex = new Texture();
        if (tex->Load(fileName))
        {
            mTextures.emplace(fileName, tex);
        }
        else
        {
            delete tex;
            tex = nullptr;
        }
    }
    return tex;
}

void Game::BeginPlay()
{
    Actor* background = new Actor(this);
    BGSpriteComponent* bgSpriteComp = new BGSpriteComponent(background);
    bgSpriteComp->SetScreenSize(Vector2(mWindowSize[0], mWindowSize[1]));
    std::vector<Texture*> bgtexs = {
        GetTexture("Assets/1034735.png")
    };
    bgSpriteComp->SetBGTextures(bgtexs);

    Actor* object = new Actor(this);
    object->SetScale(0.5);
    SpriteComponent* sc = new SpriteComponent(object);
    sc->SetTexture(GetTexture("Assets/1034735.png"));
}

void Game::EndPlay()
{
    // Delete actors
    while (!mActors.empty()) {
        delete mActors.back();
    }
    
    /* Destroy textures */
    for (auto i : mTextures)
    {
        i.second->Unload();
        delete i.second;
    }
    mTextures.clear();

}

void Game::FullScreenToggle()
{
    SDL_SetRelativeMouseMode(SDL_TRUE);
    mIsFullscreen = !mIsFullscreen;
    if (mIsFullscreen)
    {
        SDL_SetWindowFullscreen(mWindow, SDL_WINDOW_FULLSCREEN);
    }
    else
    {
        SDL_SetWindowFullscreen(mWindow, 0);
    }
}

void Game::AddActor(Actor* actor)
{
    if (mUpdatingActors) {
        mPendingActors.emplace_back(actor);
    }
    else {
        mActors.emplace_back(actor);
    }
}

void Game::RemoveActor(Actor* actor)
{
    if (mUpdatingActors) {
        mPendingActors.erase(std::remove( mPendingActors.begin(), mPendingActors.end(), actor));
    }
    else {
        mActors.erase(std::remove(mActors.begin(), mActors.end(), actor));
    }
}

void Game::AddSprite(SpriteComponent* sprite)
{
    // Find the insertion point in the sorted vector
    // (The first element with a highter draw order than me)
    int myDrawOrder = sprite->GetDrawOrder();
    auto iter = mSprites.begin();
    for (; iter != mSprites.end(); ++iter) {
        if (myDrawOrder < (*iter)->GetDrawOrder()) {
            break;
        }
    }
    mSprites.insert(iter, sprite);
}

void Game::RemoveSprite(SpriteComponent* sprite)
{
    auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
    mSprites.erase(iter);
}
