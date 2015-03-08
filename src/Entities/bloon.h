#ifndef BLOON_H
#define BLOON_H

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../Core/entity.h"
#include "../Core/image.h"
#include "../Core/utils.h"

class Bloon: public Entity {

	public:
		Bloon();
		virtual ~Bloon();
		void update();
		float getProgression();
		void receiveDamage();
		void receiveDamage(int damage);
		bool isAlive();

	private:
    	int m_life;
    	int m_speed;
    	float m_progression;


};

#endif //BLOON_H