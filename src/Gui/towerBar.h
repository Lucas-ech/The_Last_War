#ifndef TOWERBAR_H
#define TOWERBAR_H

#include <stdexcept>
#include <array>
#include <SFML/Graphics.hpp>
#include "../Core/entity.h"
#include "interaction.h"
#include "../resourceidentifiers.h"
#include "../identifiers.h"
#include "../Entities/tower.h"

//TODO: Remove Entity inheritance
class TowerBar : public Entity {

	public:
		TowerBar(const TextureHolder& textureHolder);
		virtual ~TowerBar();
		void update(Interaction *interaction);
		void update();
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
		static constexpr int POS_X = 1140;
		static constexpr int POS_Y = 50;
		static constexpr float ITEM_SIZE = 45.0f;
		static constexpr float MARGIN_TOP = 100;
		static constexpr float MARGIN_LEFT = 5;

	private:
		const TextureHolder& m_textureHolder;
        std::array<sf::Sprite*, ID::TowerCount> m_towers;

};

#endif //TOWERBAR_H
