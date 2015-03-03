#include "bloon.h"

Bloon::Bloon(): Drawable(), m_progression(0), m_speed(1) {
	m_position.x = 0;
	m_position.y = 0;
	m_position.w = 0;
	m_position.h = 0;
	m_dstrect.w = m_dstrect.h = 45;
	m_dstrect.x = m_dstrect.y = 10;
	m_surface = IMG_Load("images/bloon_4.png");
	if(m_surface == NULL) {
		throw std::runtime_error("Image non trouvée");
	}
}

Bloon::~Bloon() {
}

void Bloon::setPosition(int x, int y) {
	m_dstrect.x = x;
	m_dstrect.y = y;
}

void Bloon::update() {
	//m_progression *= 1+m_speed/100;
	m_progression += 0.002*m_speed;
}

float Bloon::getProgression() {
	return m_progression;
}
