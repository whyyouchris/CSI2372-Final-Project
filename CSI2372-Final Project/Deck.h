#pragma once
#ifndef DECK_H
#define DECK_H
#include <memory>

template <class T> 
class Deck
{
	std::vector<T> deck;
public:
	Deck();
	~Deck();
	std::shared_ptr<T> draw();
};

#endif