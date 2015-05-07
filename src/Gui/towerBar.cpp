#include "towerBar.h"

TowerBar::TowerBar(const TextureHolder& textureHolder) : Entity(), m_textureHolder(textureHolder) {
	setTexture(textureHolder.get(Textures::TowerBar));

	for(int i = 0; i < ID::TowerCount; ++i) {
		m_towers[i] = new sf::Sprite();
		m_towers[i]->setTexture(textureHolder.get(Textures::Tower));
		m_towers[i]->setPosition(870, POS_Y + i*60);
	}
}

TowerBar::~TowerBar() {
	for(int i = 0; i < ID::TowerCount; ++i) {
		if(m_towers[i] != NULL) {
			delete m_towers[i];
		}
	}
}

void TowerBar::update(Interaction *interaction) {
	for(int i = 0; i < ID::TowerCount; ++i) {
		sf::FloatRect towerPos = m_towers[i]->getGlobalBounds();
		sf::Vector2i mousePos = sf::Mouse::getPosition();
		if(!interaction->isSelectedTower()) {
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mousePos.x >= towerPos.left && mousePos.x <= towerPos.left+towerPos.width && mousePos.y >= towerPos.top && mousePos.y <= towerPos.top+towerPos.height) {
				Tower *tower = new Tower(m_textureHolder);
	            interaction->setSelectedTower(tower);
			}
		}
	}
}

void TowerBar::update() {
}

void TowerBar::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	Entity::draw(target, states);
	for(int i = 0; i < ID::TowerCount; ++i) {
		target.draw(*m_towers[i], states);
	}
}