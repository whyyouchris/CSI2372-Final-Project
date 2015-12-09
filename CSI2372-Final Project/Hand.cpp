#include "Hand.h"
#include <iostream>
#include <string>



Hand::Hand()
{
	std::list<std::shared_ptr<AnimalCard>>* playerHand;
	playerHand = new std::list<std::shared_ptr<AnimalCard>>();
}

Hand& Hand ::operator += (std::shared_ptr<AnimalCard> card) {
	std::list<std::shared_ptr<AnimalCard>>* playerHand;
	playerHand->push_back(card);
}

Hand& Hand::operator -= (std::shared_ptr<AnimalCard> card) {
	std::list<std::shared_ptr<AnimalCard>>* playerHand;
	bool hasCard = std::find(playerHand->begin(), playerHand->end(), card) != playerHand->end();
	if (hasCard = true) {
		playerHand->remove(card);
		return *this;
	}
}

std::shared_ptr<AnimalCard> Hand::operator[] (int x) {
	std::list<std::shared_ptr<AnimalCard> >::iterator iter = playerHand->begin();
	std::advance(iter, x);
	return *iter;
}

int Hand::noCards() {
	return playerHand->size();
}

std::list<std::shared_ptr<AnimalCard>>& Hand::getList() {
	std::list<std::shared_ptr<AnimalCard>>* playerHand;
	return *playerHand;
}



