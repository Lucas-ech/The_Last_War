#include "tower.h"

Tower::Tower(const TextureHolder& textureHolder): Entity(), m_shotFrequency(1000), m_range(60) {
	//m_dstrect.x = m_dstrect.y = 0;
	//setSurface(Image::load("images/tower_1.png", &m_dstrect));
	//TODO: Fuite de mémoire
    setTexture(textureHolder.get(Textures::Tower));
}

Tower::~Tower() {
	/*while(m_bullets.size() > 0) {
		delete m_bullets.front();
		m_bullets.pop_front();
	}*/
}

void Tower::update() {
	/*if(m_lastShot + m_shotFrequency < SDL_GetTicks()) {
		m_bullets.push_back(new Bullet());
		m_bullets.back()->setPosition(m_dstrect.x, m_dstrect.y);
		m_lastShot = SDL_GetTicks();
	}*/
}

void Tower::shoot(Bloon *bloon) {
}
