#include "../include/Game.h"
#include <stdio.h>

void Game::run()
{
    m_window = SDL_CreateWindow("GE2 | FSM", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1366, 768, SDL_WINDOW_INPUT_FOCUS);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    if (!(m_window && m_renderer)) {
        printf("Something went wrong while creating the SDL window and renderer: %s\n", SDL_GetError());
        exit(1);
    }

    p_inputHandler = InputHandler::getInstance();
    m_keyboard.addHandler(p_inputHandler);

    TextureManager* tm = TextureManager::getInstance();
    tm->add("IDLE", loadTextures("assets/ChikBoy_idle.png"));
    tm->add("WALK", loadTextures("assets/ChikBoy_run.png"));
    tm->add("JUMP", loadTextures("assets/ChikBoy_jump.png"));
    tm->add("FALL", loadTextures("assets/ChikBoy_fall.png"));
    tm->add("CROUCH", loadTextures("assets/ChikBoy_crouch_idle.png"));
    tm->add("CROUCH_WALK", loadTextures("assets/ChikBoy_crouch_walk.png"));

    m_player = new Player();
    m_player->setPlayerState(new IdleLeftState());

    Clock clock;
    Time lag(0U);
    const Time MS_PER_UPDATE = 1000U / 60U;
    clock.start();

    while (m_isRunning)
    {
        Time dT = clock.restart();
        lag += dT;
        processEvents();

        while (lag > MS_PER_UPDATE)
        {
            update(MS_PER_UPDATE);
            lag -= MS_PER_UPDATE;
        }

        update(dT);
        render();
    }
}

////////////////////////////////////////////////////////////

SDL_Texture* Game::loadTextures(std::string t_path)
try
{
    SDL_Surface* temp = IMG_Load(t_path.c_str());

    if (!temp)
        throw SDL_GetError();

    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, temp);

    if (!texture)
        throw SDL_GetError();

    SDL_FreeSurface(temp);

    return texture;
}
catch (const std::exception& e)
{
    printf(e.what());
    return nullptr;
}

////////////////////////////////////////////////////////////

void Game::processEvents()
{
    SDL_Event sdl_event;
    SDL_PollEvent(&sdl_event);

    if (SDL_QUIT == sdl_event.type)
        m_isRunning = false;

    m_keyboard.handleInput(sdl_event);

    InputEvent e;
    p_inputHandler->poll(e);

    if (InputID::EXIT == e.ID) 
        m_isRunning = false;
    else if (InputID::NONE != e.ID)
        m_player->handleInput(e);
}

////////////////////////////////////////////////////////////

void Game::update(Time t_dT)
{
    m_player->update(t_dT);
}

////////////////////////////////////////////////////////////

void Game::render()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    
    m_player->getAnimatedSprite().draw(m_renderer);

    SDL_RenderPresent(m_renderer);
}

////////////////////////////////////////////////////////////

void Game::cleanUp()
{
    SDL_Quit();
}