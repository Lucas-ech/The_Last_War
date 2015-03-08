#include "image.h"

SDL_Surface* Image::load(char *path, SDL_Rect *coord) {
	SDL_Surface *surface = IMG_Load(path);
	if(surface == NULL) {
		throw std::runtime_error("Image non trouvée");
	}

	std::ifstream fp;
	fp.open(path, std::ios::binary);


	if(getImageType(fp) == PNG) {
		// On place le curseur à l'endroit où les dimensions sont présentes
		fp.seekg(16);

		coord->w = fp.get() << 24 | fp.get() << 16 | fp.get() << 8 | fp.get();
		coord->h = fp.get() << 24 | fp.get() << 16 | fp.get() << 8 | fp.get();


	}
	return surface;
}

Type Image::getImageType(std::ifstream &fp) {
	std::streampos oldPos = fp.tellg();
	fp.seekg(0);
	int sign[4] = {fp.get(), fp.get(), fp.get(), fp.get()};
	fp.seekg(oldPos);
	if(sign[0] == 0x89 && sign[1] == 0x50 && sign[2] == 0x4e && sign[3] == 0x47) {
		return PNG;
	}
	return UNKNOWN;
}