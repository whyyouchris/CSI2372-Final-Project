#include "Deck.h"
#include "AnimalCard.h"
#include <iostream>
#include <vector>
#include <memory>

template <class T>
Deck<T>::Deck()
{
	AnimalCard temp[52];
	std::vector<T> deck = temp;

}

template <class T>
Deck<T>::~Deck()
{
	delete[] deck;
}

template <class T>
std::shared_ptr<T> Deck<T>::draw() {
	AnimalCard temp;
	temp = deck.front;
	assert(!deck.empty());
	deck.erase(deck.begin());
	return temp;
}