#include "game.h"

int main ( int argc, char** argv )
{
    // load an image
    SDL_Surface* carte = IMG_Load("images/grass_1.png");

    Game game;
    game.Lecture();
    game.loadMap("grassland");
    try {
        game.mainLoop();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}
