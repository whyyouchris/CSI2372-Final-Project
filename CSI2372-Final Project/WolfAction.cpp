#include "WolfAction.h"



WolfAction::WolfAction()
{
}


WolfAction::~WolfAction()
{
}

QueryResult WolfAction::query(int player) {
	QueryResult query = QueryResult();
	int coord = 0;

	std::cout << "Please input the coordinates of the card you want to take" << std::endl;
	std::cout << "X coordinate: ";
	std::cin >> coord;
	query.selectX(coord);
	std::cout << std::endl;
	std::cout << "Y coordinate: ";
	std::cin >> coord;
	query.selectY(coord);
	return query;
}

void WolfAction::perform(Table& table, Player* player, QueryResult query) {

}