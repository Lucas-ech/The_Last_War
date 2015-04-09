#ifndef TOWERBAR_H
#define TOWERBAR_H

#include <stdexcept>
#include <array>
#include <SDL/SDL.h>
#include "../Core/drawable.h"
#include "../Core/image.h"
#include "../identifiers.h"

class TowerBar : public Drawable {

	public:
		TowerBar();
		virtual ~TowerBar();
		void draw(SDL_Surface *screen);

	private:
        std::array<SDL_Surface*, ID::TowerCount> m_towers;
        std::array<SDL_Rect, ID::TowerCount> m_pos;

};

#endif //TOWERBAR_H
