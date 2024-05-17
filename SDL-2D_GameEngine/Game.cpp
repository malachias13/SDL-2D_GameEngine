#include "Game.h"
#include "Actor.h"
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
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
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

    // Creating the window
    flags += SDL_WINDOW_FULLSCREEN_DESKTOP;
    mWindow = SDL_CreateWindow("2D Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        mWindowSize[0], mWindowSize[1], flags);
    if (!mWindow) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }

    // Renderer
    mRenderer = SDL_CreateRenderer(mWindow, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!mRenderer) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return false;
    }

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

    SDL_DestroyWindow(mWindow);
    SDL_DestroyRenderer(mRenderer);
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

    // Updating all actors
    mUpdatingActors = true;

    for (auto actor : mActors) {
        actor->Update(mDeltaTime);
    }
    mUpdatingActors = false;

    // Move pending actors to mActors
    for (auto pending : mPendingActors) {
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
    SDL_SetRenderDrawColor(
        mRenderer,
        54, 69, 79, 255
    );
    // Clearing the back buffer to the current color.
    SDL_RenderClear(mRenderer);

    // Draw all sprite components
    for (auto sprite : mSprites)
    {
        sprite->Draw(mRenderer);
    }

    // Setting the render color to white so things can be seen.
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);





    // Swap front buffer and back buffer
    SDL_RenderPresent(mRenderer);
}

SDL_Texture* Game::GetTexture(const std::string& fileName)
{
    SDL_Texture* tex = nullptr;
    // Is the texture already in the map?
    auto iter = mTextures.find(fileName);
    if (iter != mTextures.end())
    {
        tex = iter->second;
    }
    else
    {
        // Load from file
        SDL_Surface* surf = IMG_Load(fileName.c_str());
        if (!surf)
        {
            SDL_Log("Failed to load texture file %s", fileName.c_str());
            return nullptr;
        }

        // Create texture from surface
        tex = SDL_CreateTextureFromSurface(mRenderer, surf);
        SDL_FreeSurface(surf);
        if (!tex)
        {
            SDL_Log("Failed to convert surface to texture for %s", fileName.c_str());
            return nullptr;
        }

        mTextures.emplace(fileName.c_str(), tex);
    }
    return tex;
}

void Game::BeginPlay()
{
    Actor* background = new Actor(this);
    background->SetPosition(Vector2(mWindowSize[0] / 2, mWindowSize[1] / 2));
    BGSpriteComponent* bgSpriteComp = new BGSpriteComponent(background);
    bgSpriteComp->SetScreenSize(Vector2(mWindowSize[0], mWindowSize[1]));
    std::vector<SDL_Texture*> bgtexs = {
        GetTexture("Assets/1034735.png")
    };
    bgSpriteComp->SetBGTextures(bgtexs);
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
        SDL_DestroyTexture(i.second);
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
