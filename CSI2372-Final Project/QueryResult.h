#ifndef QUERYRESULT_H_INCLUDED
#define QUERYRESULT_H_INCLUDED
#include "Table.h"
#include "Player.h"

class QueryResult
{
	
public:
	QueryResult();
	~QueryResult();
	QueryResult query(int);
	void perform(Table&, Player*, QueryResult);
	void selectX(int);
	void selectY(int);

	
};
#endif

