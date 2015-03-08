#include "drawable.h"

Drawable::Drawable(): m_surface(NULL) {
	m_srcrect.x = m_dstrect.x = 0;
	m_srcrect.y = m_dstrect.y = 0;
	m_srcrect.w = m_dstrect.w = 0;
	m_srcrect.h = m_dstrect.h = 0;
}

Drawable::~Drawable() {
	if(m_surface != NULL) {
		SDL_FreeSurface(m_surface);
	}
}

void Drawable::draw(SDL_Surface *screen) {
	if(m_surface == NULL) {
		throw std::runtime_error("Surface is not drawable");
	}
	SDL_BlitSurface(m_surface, NULL, screen, &m_dstrect);
}

void Drawable::setPosition(int x, int y) {
	m_dstrect.x = x;
	m_dstrect.y = y;
}

const SDL_Rect& Drawable::getCoordinates() {
	return m_dstrect;
}