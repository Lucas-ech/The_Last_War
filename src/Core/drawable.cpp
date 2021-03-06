#include "drawable.h"

Drawable::Drawable(): m_surface(NULL), m_orgSurface(NULL),
m_pos({0,0,0,0}), m_dstrect({0,0,0,0}), m_srcrect({0,0,0,0}) {

}

Drawable::~Drawable() {
	if(m_surface != NULL) {
		SDL_FreeSurface(m_surface);
	}

	if(m_orgSurface != NULL) {
		SDL_FreeSurface(m_orgSurface);
	}
}

void Drawable::draw(SDL_Surface *screen) {
	if(m_surface == NULL) {
		throw std::runtime_error("Surface is not drawable");
	}
	SDL_BlitSurface(m_surface, NULL, screen, &m_dstrect);
}

void Drawable::rotate(double angle) {
	if (!m_surface) {
		SDL_FreeSurface(m_surface);
	}

	m_surface = rotozoomSurface(m_orgSurface, angle, 1.0, 1);

	m_dstrect.x = (m_pos.x - m_surface->w/2);
	m_dstrect.y = (m_pos.y - m_surface->h/2);
}

void Drawable::setPosition(int x, int y) {
	m_pos.x = x;
	m_pos.y = y;
	m_dstrect.x = (x - m_surface->w/2);
	m_dstrect.y = (y - m_surface->h/2);
}

SDL_Rect Drawable::getCoordinates() {
	return m_pos;
}

Uint16 Drawable::getWidth() const {
	return m_orgSurface->w;
}

Uint16 Drawable::getHeight() const {
	return m_orgSurface->h;
}

void Drawable::setSurface(SDL_Surface *surface) {
	m_orgSurface = surface;
	// Copie de la surface originale dans m_surface
	m_surface = SDL_ConvertSurface(surface, surface->format, SDL_SWSURFACE);
}