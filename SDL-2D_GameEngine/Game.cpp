#include "Game.h"

Game::Game():
    mWindow(nullptr),
    mIsRunning(true)
{
}

bool Game::Initialize()
{
    flag = SDL_WINDOW_RESIZABLE;
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if (sdlResult != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }
    // Creating the window
    mWindow = SDL_CreateWindow("2D Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1024, 768, flag);
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
        flag += SDL_WINDOW_FULLSCREEN;
    }
}

void Game::UpdateGame()
{
    // wailt until 16ms has elapsed since last frame (Cape the frame rate at 60FPS)
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));

    /* Delta time is the difference in ticks from last frame
     (converted to seconds) */
    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
    // clamp maximum delta time value
    if (deltaTime > 0.05f)
    {
        deltaTime = 0.05f;
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

    // Setting the render color to white so things can be seen.
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);





    // Swap front buffer and back buffer
    SDL_RenderPresent(mRenderer);
}
