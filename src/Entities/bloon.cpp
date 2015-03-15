#include "bloon.h"

Bloon::Bloon(): Entity(), m_life(5), m_speed(1), m_progression(0) {
	m_dstrect.x = m_dstrect.y = 0;
	setSurface(Image::load("images/bloon_4.png", &m_dstrect));
}

Bloon::~Bloon() {
}

void Bloon::update() {
	m_progression += 0.002*m_speed;
}

float Bloon::getProgression() {
	return m_progression;
}

void Bloon::receiveDamage() {
	m_life--;
}

void Bloon::receiveDamage(int damage) {
	m_life -= damage;
}

bool Bloon::isAlive() {
	return m_life > 0;
}