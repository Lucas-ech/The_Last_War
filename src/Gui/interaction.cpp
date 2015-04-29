#include "interaction.h"

Interaction::Interaction(): m_selectedTower(NULL) {

}

bool Interaction::setSelectedTower(Tower *tower) {
	if(m_selectedTower == NULL) {
		std::cout << "Setting a tower" << std::endl;
		m_selectedTower = tower;
		return true;
	}
	return false;
}

bool Interaction::isSelectedTower() {
	return (m_selectedTower != NULL);
}

Tower* Interaction::getSelectedTower() {
	return m_selectedTower;
}

void Interaction::releaseSelectedTower() {
	m_selectedTower = NULL;
}