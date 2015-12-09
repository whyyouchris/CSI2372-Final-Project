#ifndef WOLFACTION_H_INCLUDED
#define WOLFACTION_H_INCLUDED
#include "QueryResult.h"

class WolfAction
{
public:
	WolfAction();
	~WolfAction();
	QueryResult query(int);
	void perform(Table&, Player*, QueryResult);
};

#endif
