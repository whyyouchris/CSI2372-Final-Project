#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED
#include "AnimalCard.h"
#include "ActionCard.h"
#include <iostream>
#include <memory>
#include <string>

class Table
{
public:
	Table();
	~Table();
	int addAt(shared_ptr<AnimalCard>, int, int);
	Table& operator+=(shared_ptr<ActionCard>);
	Table& operator-=(shared_ptr<ActionCard>);
	shared_ptr<AnimalCard> pickAt(int, int);
	bool win(string& animal);
private:
	shared_ptr<AnimalCard> cards[103][103];
	bool match(Animal, Animal);
	void animalCount(shared_ptr<AnimalCard>, bool);
	int counts[5] = { 0,0,0,0,0 };
};

#endif

