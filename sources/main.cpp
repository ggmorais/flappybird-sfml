#include <Game.hpp>

int main()
{
    Game *game = new Game();

    while (game->isRunning()) {
        game->update();
        game->render();
    }

    return 1;
}