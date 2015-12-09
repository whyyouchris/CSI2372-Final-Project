
#ifndef ACTIONCARD_H_INCLUDED
#define ACTIONCARD_H_INCLUDED
#include "QueryResult.h"
#include "Table.h"
#include "Player.h"

class ActionCard
{
	QueryResult temp;
	
public:
	//ActionCard();
	//~ActionCard();
	virtual	QueryResult query();
	virtual void perform(Table&, Player*, QueryResult);
	
};

#endif

