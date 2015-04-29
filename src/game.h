#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <deque>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
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
        int m_money;
        sf::RenderWindow m_window;
        sf::Event m_windowEvent;
        sf::Sprite m_map;
        sf::Sprite m_towerBar;
        //std::deque<Bloon*> m_bloon;
        std::deque<Tower*> m_tower;
        std::vector<Point> m_path;
};

#endif // GAME_H_INCLUDED
