#define DEBUG_MSG(msg) (std::cout << msg << std::endl);

#include <iostream>
#include "../include/Game.h"

int main(int argc, char** argv)
{
    Game* game = new Game();
    game->run();
    return 0;
}