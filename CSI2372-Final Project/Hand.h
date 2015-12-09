#ifndef HAND_H_INCLUDED
#define HAND_H_INCLUDED
#include <memory>
#include <list>
#include <iostream>
#include "AnimalCard.h"


class Hand
{
	std::list<std::shared_ptr<AnimalCard>>* playerHand;
public:
	
	Hand();
	Hand& operator += (std::shared_ptr<AnimalCard>);
	Hand& operator -= (std::shared_ptr<AnimalCard>);
	std::shared_ptr<AnimalCard> operator[] (int);
	int noCards();
	std::list<std::shared_ptr<AnimalCard>>&  getList();
	
	friend std::ostream& operator << (std::ostream&, Hand&) {
		for (int i = 0; i < playHand.noCards(); i++) {
			output << i << " ";
		}
		output << std::endl;
		for (std::list<std::shared_ptr<AnimalCard>>::iterator iter = playHand.getList().begin();
		iter != playHand.getList().end(); iter++) {
			output << *iter;
		}
		return output;
	}
		
};

#endif

