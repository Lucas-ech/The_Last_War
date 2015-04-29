#ifndef INTERACTION_H
#define INTERACTION_H

#include "../Entities/tower.h"

class Interaction {

	public:
		Interaction();
		bool setSelectedTower(Tower *tower);
		bool isSelectedTower();
		Tower* getSelectedTower();
		void releaseSelectedTower();

	private:
		Tower *m_selectedTower;

};

#endif