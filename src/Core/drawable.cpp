#include "drawable.h"

Drawable::Drawable() {
	m_srcrect.x = m_dstrect.x = 0;
	m_srcrect.y = m_dstrect.y = 0;
	m_srcrect.w = m_dstrect.w = 0;
	m_srcrect.h = m_dstrect.h = 0;
}

Drawable::~Drawable() {
	SDL_FreeSurface(m_surface);
}

void Drawable::draw(SDL_Surface *screen) {
	if(m_surface == NULL) {
		throw std::runtime_error("Surface is not drawable");
	}
	SDL_BlitSurface(m_surface, NULL, screen, &m_dstrect);
}