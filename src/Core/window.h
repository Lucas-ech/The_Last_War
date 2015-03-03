#ifndef WINDOW_H
#define WINDOW_H

#include <stdexcept>
#include <string>
#include <SDL/SDL.h>
#include "drawable.h"

class Window {

	public:
		Window();
		~Window();
		void update(SDL_Event &event);
		void draw(Drawable *drawable);
		void blit(SDL_Surface *src, SDL_Rect *srcrect, SDL_Rect *dstrect);
		void flip();
		bool isDone();
		static const int WIDTH = 840;
		static const int HEIGHT = 600;

	private:
		SDL_Surface *m_screen;
		bool m_isDone;

};

#endif //WINDOW_H