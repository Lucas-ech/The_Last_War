#ifndef TOWER_H
#define TOWER_H

#include <deque>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../Core/resourceholder.h"
#include "../resourceidentifiers.h"
#include "../Core/entity.h"
#include "../Entities/bloon.h"
#include "../Entities/bullet.h"

class Tower: public Entity {

	public:
		Tower(const TextureHolder& textureHolder);
		virtual ~Tower();
		void update();
		void shoot(Bloon *bloon);

	private:
		float m_shotFrequency;
		int m_range;
		//std::deque<Bullet*> m_bullets;


};

#endif //TOWER_H