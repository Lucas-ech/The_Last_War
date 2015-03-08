#ifndef TOWER_H
#define TOWER_H

#include <deque>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../Core/entity.h"
#include "../Core/image.h"
#include "../Entities/bullet.h"

class Tower: public Entity {

	public:
		Tower();
		~Tower();
		void draw(SDL_Surface *screen);
		void update();

	private:
		float m_shotFrequency;
		Uint32 m_lastShot;
		std::deque<Bullet*> m_bullets;


};

#endif //TOWER_H