#ifndef TOWER_H
#define TOWER_H

#include <deque>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_gfxPrimitives.h>
#include "../Core/entity.h"
#include "../Core/image.h"
#include "../Entities/bloon.h"
#include "../Entities/bullet.h"

class Tower: public Entity {

	public:
		Tower();
		virtual ~Tower();
		void draw(SDL_Surface *screen);
		void drawRange(SDL_Surface *screen);
		void update();
		void shoot(Bloon *bloon);

	private:
		float m_shotFrequency;
		Uint32 m_lastShot;
		int m_range;
		std::deque<Bullet*> m_bullets;


};

#endif //TOWER_H