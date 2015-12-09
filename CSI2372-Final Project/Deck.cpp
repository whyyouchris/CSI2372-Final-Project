#include "Deck.h"
#include <iostream>
#include <vector>
#include <memory>

template <class T> class Deck : public std::vector<T> {
public:
	Deck(std::vector<T> list) : std::vector<T>(list) {};
	T draw();
};


template <class T> T Deck<T>::draw() {
	if (std::vector<T>::empty()) {
		return NULL;
	}
	T card = std::vector<T>::back();
	std::vector<T>::pop_back();
	return card;
};


