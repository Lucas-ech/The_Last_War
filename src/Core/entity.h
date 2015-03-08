#ifndef ENTITY_H
#define ENTITY_H

#include <cmath>
#include "drawable.h"
#include "window.h"

class Entity: public Drawable {

	public:
		Entity();
		virtual ~Entity();
		bool isColliding(Entity *entity);
		bool isNearOf(Entity *entity, int radius);
		bool isOutOfScreen();
		virtual void update() = 0;

	private:

};

#endif //ENTITY_H