#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <stdexcept>
#include <SDL/SDL.h>
#include <SDL/SDL_rotozoom.h>

class Drawable {

	public:
		Drawable();
		virtual ~Drawable();
		virtual void draw(SDL_Surface *screen);
		void rotate(double angle);
		void setPosition(int x, int y);
		SDL_Rect getCoordinates();
		Uint16 getWidth() const;
		Uint16 getHeight() const;
		int getAngle() const;

	protected:
		void setSurface(SDL_Surface *surface);
		SDL_Rect m_pos;
		SDL_Rect m_srcrect;
		SDL_Rect m_dstrect;
		float m_x, m_y;
 		SDL_Surface *m_surface;
		SDL_Surface *m_orgSurface;
		int m_angle;
};

#endif //DRAWABLE_H