#include "../include/Game.h"
#include <stdio.h>

void Game::run()
{
    SDL_CreateWindowAndRenderer(1366, 768, SDL_WINDOW_INPUT_FOCUS, &m_window, &m_renderer);

    m_keyboard.addHandler(&m_inputHandler);

    m_player = new Player();

    if (!(m_window && m_renderer)) {
        printf("Something went wrong while creating the SDL window and renderer: %s\n", SDL_GetError());
        exit(1);
    } else {
        while (m_isRunning)
        {
            processEvents();
            update();
            render();
        }
    }
}

////////////////////////////////////////////////////////////

void Game::processEvents()
{
    SDL_Event sdl_event;
    SDL_PollEvent(&sdl_event);

    if (SDL_QUIT == sdl_event.type)
        m_isRunning = false;
    else
        m_keyboard.handleInput(sdl_event);

    InputEvent e;
    m_inputHandler.poll(e);
    m_player->handleInput(e);
}

////////////////////////////////////////////////////////////

void Game::update() {}

////////////////////////////////////////////////////////////

void Game::render()
{
    SDL_RenderClear(m_renderer);
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    
    m_player->draw(m_renderer);

    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderPresent(m_renderer);
}

////////////////////////////////////////////////////////////

void Game::cleanUp()
{
    SDL_Quit();
}