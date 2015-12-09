#pragma once
#ifndef DECK_H
#define DECK_H
#include "AnimalCard.h"
#include <memory>

template <class T> 
class Deck
{
	std::vector<T> deck;
public:

	std::shared_ptr<T> draw();
};

#endif