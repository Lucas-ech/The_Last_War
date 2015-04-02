#ifndef UTILS_H
#define UTILS_H

struct Vec {
	float x;
	float y;
	Vec(float x, float y) {
		this->x = x;
		this->y = y;
	}
};

int intcmp(int a, int b);

#endif //UTILS_H