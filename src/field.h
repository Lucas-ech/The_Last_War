#ifndef FIELD_H
#define FIELD_H

#include <SFML/Graphics.hpp>

class Field : public sf::Drawable {

	public:
		Field();
		virtual ~Field();
		void update();

	private:

};

#endif //FIELD_H