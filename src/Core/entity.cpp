#include "entity.h"

Entity::Entity(): Drawable() {

}

Entity::~Entity() {

}

bool Entity::isColliding(Entity *entity) {
	const SDL_Rect &coord = entity->getCoordinates();
	//TODO: Gestion des collisions plus précises
	if(coord.x >= m_dstrect.x && coord.x <= m_dstrect.x+m_dstrect.w && coord.y >= m_dstrect.y && coord.y <= m_dstrect.x+m_dstrect.h) {
		return true;
	}
	return false;
}

bool Entity::isNearOf(Entity *entity, int radius) {
	const SDL_Rect &coord = entity->getCoordinates();
	/*
	 * Équation d'un cercle r² = (x-a)² + (y-b)²
	 * Si (x-a)² + (y-b)² <= r², alors le point (a,b) est dans ou sur le cercle
	 * Sinon il est en dehors
	 */
	return (pow((coord.x - m_dstrect.x), 2) + pow((coord.y - m_dstrect.y), 2)) <= pow(radius, 2);
}

bool Entity::isOutOfScreen() {
	return m_dstrect.x + m_dstrect.w < 0 || m_dstrect.x >= Window::WIDTH || m_dstrect.y + m_dstrect.h < 0 || m_dstrect.y >= Window::HEIGHT;
}