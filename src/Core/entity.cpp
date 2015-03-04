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