#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <stdexcept>
#include <SDL/SDL.h>

class Drawable {

	public:
		Drawable();
		virtual ~Drawable();
		virtual void draw(SDL_Surface *screen);
		void setPosition(int x, int y);
		const SDL_Rect& getCoordinates();

	protected:
		SDL_Surface *m_surface;
		SDL_Rect m_srcrect;
		SDL_Rect m_dstrect;

};

#endif //DRAWABLE_H