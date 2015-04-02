#include "tower.h"

Tower::Tower(): Entity(), m_shotFrequency(1000), m_lastShot(0), m_range(60) {
	m_dstrect.x = m_dstrect.y = 0;
	setSurface(Image::load("images/tower_1.png", &m_dstrect));
}

Tower::~Tower() {
	while(m_bullets.size() > 0) {
		delete m_bullets.front();
		m_bullets.pop_front();
	}
}

void Tower::draw(SDL_Surface *screen) {
	Drawable::draw(screen);
	for(unsigned int i = 0; i < m_bullets.size(); ++i) {
		m_bullets[i]->update();
		m_bullets[i]->draw(screen);

	}
}

void Tower::drawRange(SDL_Surface *screen) {
	filledCircleColor(screen, m_pos.x, m_pos.y, m_range, 0x00000066);
}

void Tower::update() {
	/*if(m_lastShot + m_shotFrequency < SDL_GetTicks()) {
		m_bullets.push_back(new Bullet());
		m_bullets.back()->setPosition(m_dstrect.x, m_dstrect.y);
		m_lastShot = SDL_GetTicks();
	}*/
}

void Tower::shoot(Bloon *bloon) {
	if(m_lastShot + m_shotFrequency < SDL_GetTicks()) {
		m_bullets.push_back(new Bullet());
		m_bullets.back()->setPosition(m_pos.x, m_pos.y);
		std::cout << m_angle << std::endl;
		m_bullets.back()->setDirection(50*cos(m_angle * M_PI / 180.0f), 50*(-sin(m_angle * M_PI / 180.0f)));
		m_bullets.back()->rotate(m_angle);
		bloon->receiveDamage();
		m_lastShot = SDL_GetTicks();
	}
}
