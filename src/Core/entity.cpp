#include "entity.h"

Entity::Entity(): Drawable() {

}

Entity::~Entity() {

}

bool Entity::isColliding(Entity *entity) {
	const SDL_Rect coord = entity->getCoordinates();
	//TODO: Gestion des collisions plus précises
	if(coord.x >= m_dstrect.x && coord.x <= m_dstrect.x && coord.y >= m_dstrect.y && coord.y <= m_dstrect.x) {
		return true;
	}
	return false;
}

bool Entity::isNearOf(Entity *entity, int radius) {
	SDL_Rect coord = entity->getCoordinates();
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

void Entity::rotateTowards(Entity *entity) {
	const SDL_Rect coord = entity->getCoordinates();

    float x, y, angle;

    x = coord.x - m_pos.x;
    y = coord.y - m_pos.y;

    angle = acos(x/sqrt(x*x + y*y)) * 180.0f / M_PI;

    if(y > 0) {
        angle *= -1;
    }
    /*else if(y == 0) {
        if(x > 0) {
            angle = 0;
        } else {
            angle = 180;
        }
    }*/
    rotate(angle);
}