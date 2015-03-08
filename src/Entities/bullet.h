#ifndef BULLET_H
#define BULLET_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../Core/entity.h"
#include "../Core/image.h"

class Bullet: public Entity {

	public:
		Bullet();
		virtual ~Bullet();
		void update();

	private:

};

#endif //BULLET_H