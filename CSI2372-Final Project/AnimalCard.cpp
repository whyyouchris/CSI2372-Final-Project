#include "AnimalCard.h"
#include <iostream>
#include <string>

AnimalCard::AnimalCard() {
	orientation = UP;
	evenOdd = EVEN;
}

AnimalCard::~AnimalCard() {
	for (int i = 0; i < CARDSIZE; i++) {
		delete[] animals[i];
	}
	delete[] animals;
}

void AnimalCard::setOrientation(Orientation _orientation) {
	orientation = _orientation;
	if (orientation == UP) {
		setRow(EVEN);
	}
	else setRow(ODD);
}

void AnimalCard::setRow(EvenOdd _evenOdd) {
	if (evenOdd != DEFAULT) {
		evenOdd = _evenOdd;
	}
}


void AnimalCard::printRow(EvenOdd _evenOdd) {//wrong
	if (_evenOdd == EVEN) {
		std::cout << animals[0][0] << animals[0][1];
	}
	else if (_evenOdd == ODD) {
		std::cout << animals[1][0] << animals[1][1];
	}
	else printRow(evenOdd);
}

bool AnimalCard::isSame(AnimalCard other) {
	return ((animals[0][0] == other.animals[0][0]
		&& animals[0][1] == other.animals[0][1]
		&& animals[1][0] == other.animals[1][0]
		&& animals[1][1] == other.animals[1][1])

		|| (animals[0][0] == other.animals[1][1]
			&& animals[0][1] == other.animals[1][0]
			&& animals[1][0] == other.animals[0][1]
			&& animals[1][1] == other.animals[0][0]));
}
