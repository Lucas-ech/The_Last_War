#ifndef IMAGE_H
#define IMAGE_H

#include <stdexcept>
#include <fstream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

enum Type {
	PNG,
	UNKNOWN
};

class Image {

	public:
		static SDL_Surface* load(char *path, SDL_Rect *coord);
		static SDL_Surface* load(char *path);

	private:
		static Type getImageType(std::ifstream &fp);

};

#endif //IMAGE_H
