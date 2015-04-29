#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include "../Core/utils.h"
#include "../Core/entity.h"

class Bullet: public Entity {

	public:
		Bullet();
		virtual ~Bullet();
		void update();
		void setDirection(float x, float y);

	private:
		Vec m_direction;

};

#endif //BULLET_H