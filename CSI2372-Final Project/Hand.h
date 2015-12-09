#ifndef HAND_H_INCLUDED
#define HAND_H_INCLUDED
#include <memory>
#include "AnimalCard.h"


class Hand
{
public:
	Hand();
	~Hand();
	Hand& operator += (std::shared_ptr<AnimalCard>);
	Hand& operator -= (std::shared_ptr<AnimalCard>);
	std::shared_ptr<AnimalCard> operator[] (int);
	int noCards();
};

#endif

