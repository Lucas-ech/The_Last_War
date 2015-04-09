#include "towerBar.h"

TowerBar::TowerBar() : Drawable() {
    m_dstrect.y = 0;
	setSurface(Image::load("images/towerBar.png", &m_dstrect));
    m_dstrect.x = 840;

    m_towers[0] = Image::load("images/tower_1.png");
    m_towers[1] = Image::load("images/tower_2.png");
}

TowerBar::~TowerBar() {

}

void TowerBar::draw(SDL_Surface *screen) {
    Drawable::draw(screen);
    for(unsigned int i = 0; i < m_towers.size(); ++i) {
        if(m_towers[i] == NULL) {
            break;
        }
        SDL_Rect a;
        a.x = m_dstrect.x;
        a.y = i * 60 + m_dstrect.y;
        //m_pos[i] = a;
        SDL_BlitSurface(m_towers[i], NULL, screen, &a);
    }
}
