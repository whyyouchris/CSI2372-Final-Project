#include "ActionCard.h"
#include "Split.cpp"


/*
ActionCard::ActionCard()
{
	
}


ActionCard::~ActionCard()
{
}
*/

QueryResult ActionCard::query() {
	return temp;
}

void ActionCard::perform(Table&, Player*, QueryResult) {

}

class WolfAction:ActionCard {

};

class BearAction:ActionCard{

};

class DeerAction:ActionCard {

};

class MooseAction:ActionCard {

};

class WolfAction:ActionCard {

};