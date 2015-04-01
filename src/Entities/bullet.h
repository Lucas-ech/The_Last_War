#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../Core/utils.h"
#include "../Core/entity.h"
#include "../Core/image.h"

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