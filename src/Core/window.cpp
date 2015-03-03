#include "window.h"

Window::Window(): m_screen(NULL), m_isDone(false) {
	// initialize SDL video
	if (SDL_Init( SDL_INIT_VIDEO ) < 0) {
		std::string error = SDL_GetError();
	    throw std::runtime_error("Unable to init SDL: " + error);
	}

	atexit(SDL_Quit);
    m_screen = SDL_SetVideoMode(WIDTH, HEIGHT, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);
}

Window::~Window() {
	SDL_FreeSurface(m_screen);
}

void Window::update(SDL_Event &event) {
	if(event.type == SDL_QUIT) {
		m_isDone = true;
	}
}

void Window::draw(Drawable *drawable) {
	drawable->draw(m_screen);
}

void Window::blit(SDL_Surface *src, SDL_Rect *srcrect, SDL_Rect *dstrect) {
	SDL_BlitSurface(src, srcrect, m_screen, dstrect);
}

void Window::flip() {
	SDL_Flip(m_screen);
}

bool Window::isDone() {
	return m_isDone;
}
