#include "Table.h"

Table::Table()
{
}


Table::~Table()
{
}

Table& Table::operator+=(shared_ptr<ActionCard> card) {
	return *this;
}


Table& Table::operator-=(shared_ptr<ActionCard> card) {
	return *this;
}



shared_ptr<AnimalCard> Table::pickAt(int x, int y) {
	if (cards[y][x] != nullptr && (x != 52 || y != 52)) {
		shared_ptr<AnimalCard> pickedCard = cards[y][x];
		cards[y][x] = NULL;
		return pickedCard;
	}
	return nullptr;
}



int Table::addAt(shared_ptr<AnimalCard> card, int x, int y) {
	if (cards[y][x] == nullptr) {
		return 0;
	}
	int numOfMatches = 0;
	bool matchedTopLeft = false;
	bool matchedTopRight = false;
	bool matchedBottomLeft = false;
	Animal topLeft = card->getAnimal(0, 0);
	Animal topRight = card->getAnimal(0, 1);
	Animal bottomLeft = card->getAnimal(1, 0);
	Animal bottomRight = card->getAnimal(1, 1);
	//check the top left for matches
	if ((cards[y][x - 1] != nullptr&&match(cards[y][x - 1]->getAnimal(0, 1), topLeft)) || (cards[y - 1][x] != nullptr&&match(cards[y - 1][x]->getAnimal(1, 0), topLeft))) {
		numOfMatches++;
		matchedTopLeft = true;
	}
	//check the top right for matches
	if (topRight != topLeft || matchedTopLeft == false) {
		if ((cards[y - 1][x] != nullptr&&match(cards[y - 1][x]->getAnimal(1, 1), topRight)) || (cards[y][x + 1] != nullptr&&match(cards[y][x + 1]->getAnimal(0, 0), topRight))) {
			numOfMatches++;
			matchedTopRight = true;
		}
	}
	//check the bottom left matches
	if ((bottomRight != topRight || matchedTopRight == false) && ((bottomRight != topRight && bottomRight != topLeft) || (matchedTopRight == false && matchedTopLeft == false))) {
		if ((cards[y][x - 1] != nullptr&&match(cards[y][x - 1]->getAnimal(1, 1), bottomLeft)) || (cards[y - 1][x] != nullptr&&match(cards[y - 1][x]->getAnimal(0, 0), bottomLeft))) {
			numOfMatches++;
			matchedBottomLeft = true;
		}
	}
	//check the bottom right matches
	if ((bottomRight != bottomLeft || matchedBottomLeft == false) && (bottomRight != topRight || matchedTopRight == false) && ((bottomRight != bottomLeft || bottomRight != topRight) || (matchedTopRight == false || matchedBottomLeft == false))) {
		if ((cards[y - 1][x] != nullptr&&match(cards[y - 1][x]->getAnimal(0, 0), bottomLeft)) || (cards[y][x + 1] != nullptr&&match(cards[y][x + 1]->getAnimal(1, 0), bottomLeft))) {
			numOfMatches++;
			matchedBottomLeft = true;
		}
	}
	if (numOfMatches > 0) {
		cards[y][x] = card;
		animalCount(cards[y][x], true);
	}
	return numOfMatches;
}
bool Table::match(Animal _animal1, Animal _animal2) {
	return (_animal1 == _animal2 || _animal1 == START || _animal1 == JOKER || _animal2 == JOKER || _animal2 == JOKER);
}



void Table::animalCount(shared_ptr<AnimalCard> card, bool addAction) {
	Animal topLeft = card->getAnimal(0, 0);
	Animal topRight = card->getAnimal(0, 1);
	Animal bottomLeft = card->getAnimal(1, 0);
	Animal bottomRight = card->getAnimal(1, 1);
	int i = -1;
	if (addAction) {
		i = 1;
	}
	if (topLeft == JOKER) {
		counts[WOLF] += i;
		counts[BEAR] += i;
		counts[MOOSE] += i;
		counts[HARE] += i;
		counts[DEER] += i;
	}
	else {
		counts[topLeft] += i;
		if (topLeft != topRight) {
			counts[topRight] += i;
		}
		if (bottomLeft != topLeft) {
			counts[topLeft] += i;
		}
		if (bottomRight != topRight&&bottomRight != bottomLeft) {
			counts[bottomRight] += i;
		}
	}

}


bool Table::win(string& animal) {
	if (animal == "wolf") return counts[WOLF] >= 12;
	if (animal == "bear") return counts[BEAR] >= 12;
	if (animal == "moose") return counts[MOOSE] >= 12;
	if (animal == "hare") return counts[HARE] >= 12;
	if (animal == "deer") return counts[DEER] >= 12;
}
