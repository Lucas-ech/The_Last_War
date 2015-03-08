#include "tower.h"

Tower::Tower(): Entity(), m_lastShot(0), m_shotFrequency(1000/5) {
	m_dstrect.x = m_dstrect.y = 0;
	m_surface = Image::load("images/tower_1.png", &m_dstrect);
}

Tower::~Tower() {

}

void Tower::draw(SDL_Surface *screen) {
	Drawable::draw(screen);
	for(int i = 0; i < m_bullets.size(); ++i) {
		m_bullets[i]->draw(screen);
	}
}

void Tower::update() {
	if(m_lastShot + m_shotFrequency < SDL_GetTicks()) {
		m_bullets.push_back(new Bullet());
		m_bullets.back()->setPosition(m_dstrect.x, m_dstrect.y);
		m_lastShot = SDL_GetTicks();
	}
}