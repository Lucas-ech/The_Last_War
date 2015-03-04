#ifndef ENTITY_H
#define ENTITY_H

#include "drawable.h"

class Entity: public Drawable {

	public:
		Entity();
		virtual ~Entity();
		bool isColliding(Entity *entity);

	private:

};

#endif //ENTITY_H