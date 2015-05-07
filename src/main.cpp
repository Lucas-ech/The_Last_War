#include "game.h"

int main ( int argc, char** argv )
{
    Game game;
    //game.loadMap("grassland");
    try {
        game.mainLoop();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    printf("Exited cleanly\n");
    return 0;
}
