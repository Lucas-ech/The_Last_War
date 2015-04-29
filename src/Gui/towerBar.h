#ifndef TOWERBAR_H
#define TOWERBAR_H

#include <stdexcept>
#include <array>
#include <SFML/Graphics.hpp>
#include "interaction.h"
#include "../identifiers.h"
#include "../Entities/tower.h"

class TowerBar : public sf::Drawable {

	public:
		TowerBar();
		virtual ~TowerBar();
		void update(Interaction *interaction);
		static constexpr float ITEM_SIZE = 45.0f;
		static constexpr float MARGIN_TOP = 100;
		static constexpr float MARGIN_LEFT = 5;

	private:

};

#endif //TOWERBAR_H
