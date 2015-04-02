#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <deque>
#include <vector>
#include <fstream>
#include <cmath>
#include "Core/window.h"
#include "Entities/bloon.h"
#include "Entities/tower.h"

struct Point
{
    int x;
    int y;
};

class Game
{
    public:
        Game();
        ~Game();
        void mainLoop();
        void processEvents();
        void drawAll();
        void Lecture();
        void loadMap(std::string file);

    private:
        SDL_Event m_event;
        int m_vague, m_nbbloon, m_inter;
        Window m_window;
        std::deque<Bloon*> m_bloon;
        std::deque<Tower*> m_tower;
        std::vector<Point> m_path;
};

#endif // GAME_H_INCLUDED
