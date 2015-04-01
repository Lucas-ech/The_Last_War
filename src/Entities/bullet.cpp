#include "bullet.h"

Bullet::Bullet(): Entity(), m_direction(0, 0) {
	m_dstrect.x = m_dstrect.y = 0;
	setSurface(Image::load("images/bullet_1.png", &m_dstrect));
}

Bullet::~Bullet() {

}

void Bullet::update() {
	//std::cout << "(" << m_direction.x << "; " << m_direction.y << ")" << std::endl;
	m_x += m_direction.x;
	m_y += m_direction.y;
}

void Bullet::setDirection(float x, float y) {
	m_direction.x = x;
	m_direction.y = y;
}
