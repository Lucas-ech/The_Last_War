#include "bullet.h"

Bullet::Bullet(): Entity() {
	m_dstrect.x = m_dstrect.y = 0;
	setSurface(Image::load("images/bullet_1.png", &m_dstrect));
}

Bullet::~Bullet() {

}

void Bullet::update() {
	m_dstrect.x += 1;
}