#include "game.h"

Game::Game(): m_money(0), m_window(sf::VideoMode(940, 600), "The Last War")
{
    m_window.setFramerateLimit(60);
}

Game::~Game()
{
    /*while(m_bloon.size() > 0) {
        delete m_bloon.front();
        m_bloon.pop_front();
    }*/
}


void Game::mainLoop() {

    sf::Texture mapTexture;
    mapTexture.loadFromFile("images/level1/map.png");
    m_map.setTexture(mapTexture);

    sf::Texture towerBarTexture;
    towerBarTexture.loadFromFile("images/TowerBar.png");
    m_towerBar.setTexture(towerBarTexture);
    m_towerBar.setPosition(840, 0);

    m_tower.push_back(new Tower());
    m_tower.back()->setPosition(200, 200);

    m_tower.push_back(new Tower());
    m_tower.back()->setPosition(45, 80);

    m_tower[0]->rotateTowards(m_tower[1]);


    while (m_window.isOpen()) {
        processEvents();
        drawAll();
    }
}

void Game::processEvents() {
    while (m_window.pollEvent(m_windowEvent)) {
        switch (m_windowEvent.type) {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::KeyPressed:
                if(m_windowEvent.key.code == sf::Keyboard::Escape) {
                    m_window.close();
                }
            default:
                break;
        }
    }
}

void Game::Lecture()
{
}

void Game::drawAll()
{
    m_window.draw(m_map);
    m_window.draw(m_towerBar);

    for(unsigned int i = 0; i < m_tower.size(); ++i)
    {
        m_window.draw(*m_tower[i]);
        m_tower[i]->update();
    }

    // Swap buffers
    m_window.display();


}

void Game::loadMap(std::string file) {
    std::cout << "Loading Map" << std::endl;
    file.insert(0, "maps/");
    std::ifstream fp;
    fp.open(file.c_str(), std::ios::binary);
    if(!fp) {
        std::cout << "Map file does not exist" << std::endl;
        return;
    }

    while(fp.good()) {
        int x = fp.get();
        int y = fp.get();
        if(fp.eof()) {
            break;
        }
        Point a;
        a.x =x;
        a.y = y;
        m_path.push_back(a);
    }

    fp.close();
}
