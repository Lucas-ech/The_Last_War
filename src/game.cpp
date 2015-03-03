#include "game.h"

Game::Game(): m_window()
{
    m_avancement = 0;
    m_vague = 0;
    m_nbbloon = 0;
    m_inter = 0;
}

Game::~Game()
{
    while(m_bloon.size() > 0) {
        m_bloon.pop_front();
    }
}


void Game::mainLoop() {
    //const float framerate = 1000/60;
    const float framerate = 1000/40;
    Uint32 beginLoop = 0, elapsedTime = 0;

    SDL_Surface *carte = IMG_Load("images/level1/map.png");

    while (!m_window.isDone())
    {
        beginLoop = SDL_GetTicks();

        processEvents();

        m_window.blit(carte, NULL, NULL);

        Affiche();

        // Updating the screen
        m_window.flip();

        elapsedTime = SDL_GetTicks() - beginLoop;
        if(elapsedTime < framerate) {
            SDL_Delay(framerate - elapsedTime);
        }
    }
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
    fscanf(fichier, "%d", &m_vague);
    fscanf(fichier, "%d", &m_nbbloon);
    fscanf(fichier, "%d", &m_inter);
    for(int i(1) ; i < m_nbbloon ; i++)
    {
        m_bloon.push_back(new Bloon());
    }
    std::cout << "Il y a " << m_bloon.size() << " bloons" << std::endl;
    fclose(fichier);
}

void Game::Affiche()
{
    float progression;
    int lowCase;
    float between, position;
    float xMoving, yMoving;
    for(int i(0); i < m_bloon.size(); ++i)
    {
        progression = m_bloon[i]->getProgression();

        position = progression*m_path.size();

        lowCase = floor(position);
        between = position - lowCase;

        xMoving = intcmp(m_path[lowCase+1].x, m_path[lowCase].x);
        yMoving = intcmp(m_path[lowCase+1].y, m_path[lowCase].y);

        m_bloon[i]->setPosition(60*(m_path[lowCase].x+(between)*xMoving), 60*(m_path[lowCase].y+(between)*yMoving));
        m_window.draw(m_bloon[i]);
        m_bloon[i]->update();
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
        std::cout << "(" << x << "; " << y << ")" << std::endl;
        m_path.push_back({x, y});
        //m_avancement = 0;
    }

    fp.close();
}
