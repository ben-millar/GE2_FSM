#include <string>
#include <array>
#include <SDL.h>
#include <SDL_image.h>

#include "../include/InputHandler.h"
#include "../include/KeyboardInput.h"

#include "Player.h"
#include "MacroCommand.h"
#include "IdleState.h"
#include "TextureManager.h"

class Game
{
private:
    SDL_Window* m_window{nullptr};
    SDL_Renderer* m_renderer{nullptr};

    InputHandler* p_inputHandler;
    KeyboardInput m_keyboard;

    Player* m_player;

    bool m_isRunning{true};
public:
    Game() = default;
    ~Game() = default;

    void run();
    SDL_Texture* loadTextures(std::string t_path);
    void processEvents();
    void update();
    void render();
    void cleanUp();

    inline bool isRunning() { return m_isRunning; }
};