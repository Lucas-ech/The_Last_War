#ifndef BLOON_H
#define BLOON_H

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Core/drawable.h"
#include "Core/utils.h"

class Bloon: public Drawable {

	public:
		Bloon();
		virtual ~Bloon();
		void setPosition(int x, int y);
		void update();
		float getProgression();

	private:
		SDL_Rect m_position;
    	int m_vie;
    	int m_speed;
    	float m_progression;


};

#endif //BLOON_H