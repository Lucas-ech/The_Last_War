#include "game.h"

Game::Game(): m_window()
{
    m_vague = 0;
    m_nbbloon = 0;
    m_inter = 0;
}

Game::~Game()
{
    while(m_bloon.size() > 0) {
        delete m_bloon.front();
        m_bloon.pop_front();
    }
}


void Game::mainLoop() {
    const float framerate = 1000/30;
    Uint32 beginLoop = 0, elapsedTime = 0;

    SDL_Surface *carte = IMG_Load("images/level1/map.png");

    m_tower.push_back(new Tower());
    m_tower.back()->setPosition(200, 250);
    m_tower.push_back(new Tower());
    m_tower.back()->setPosition(250, 400);
    m_tower.push_back(new Tower());
    m_tower.back()->setPosition(350, 50);
    m_tower.push_back(new Tower());
    m_tower.back()->setPosition(450, 282);

    TowerBar towerBar;

    while (!m_window.isDone())
    {
        beginLoop = SDL_GetTicks();

        processEvents();

        m_window.blit(carte, NULL, NULL);

        for(unsigned int i = 0; i < m_bloon.size(); ++i) {
            for(unsigned int j = 0; j < m_tower.size(); ++j) {
                if(m_tower[j]->isNearOf(m_bloon[i], 150)) {
                    m_tower[j]->rotateTowards(m_bloon[i]);
                    m_tower[j]->shoot(m_bloon[i]);
                    if(!m_bloon[i]->isAlive()) {
                        delete m_bloon[i];
                        m_bloon.erase(m_bloon.begin() + i);
                    }
                }
            }
        }

        drawAll();
        m_window.draw(&towerBar);

        // Updating the screen
        m_window.flip();

        elapsedTime = SDL_GetTicks() - beginLoop;
        if(elapsedTime < framerate) {
            SDL_Delay(framerate - elapsedTime);
        }
    }

    SDL_FreeSurface(carte);
}

void Game::processEvents() {
    while (SDL_PollEvent(&m_event)) {
        m_window.update(m_event);

        // check for messages
        switch (m_event.type)
        {
            case SDL_KEYDOWN:
                break;
        }
    }
}

void Game::Lecture()
{
    FILE *fichier;
    fichier = fopen("levels/lvl1.txt", "r");
    if(fichier == NULL) {
        std::cerr << "Level can't be loaded" << std::endl;
        return;
    }
    fscanf(fichier, "%10d", &m_vague);
    fscanf(fichier, "%10d", &m_nbbloon);
    fscanf(fichier, "%10d", &m_inter);
    for(int i = 0 ; i < m_nbbloon ; ++i)
    {
        m_bloon.push_back(new Bloon());
    }
    std::cout << "Il y a " << m_bloon.size() << " bloons" << std::endl;
    fclose(fichier);
}

void Game::drawAll()
{
    float progression;
    int lowCase;
    float between, position;
    int xMoving, yMoving;
    for(unsigned int i = 0; i < m_bloon.size(); ++i)
    {
        progression = m_bloon[i]->getProgression();

        position = progression * m_path.size();

        lowCase = static_cast<int>(floor(position));
        between = position - lowCase;

        xMoving = intcmp(m_path[lowCase+1].x, m_path[lowCase].x);
        yMoving = intcmp(m_path[lowCase+1].y, m_path[lowCase].y);

        m_bloon[i]->setPosition(
            60*(m_path[lowCase].x+(between)*xMoving)+m_bloon[i]->getWidth()/2,
            60*(m_path[lowCase].y+(between)*yMoving)+m_bloon[i]->getHeight()/2
        );
        m_window.draw(m_bloon[i]);
        m_bloon[i]->update();
    }

    for(unsigned int i = 0; i < m_tower.size(); ++i)
    {
        m_window.draw(m_tower[i]);
        m_tower[i]->update();
    }
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
