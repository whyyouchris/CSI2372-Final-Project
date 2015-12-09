#include <queue>
#include <memory>
#include <ostream>
#include "Split.cpp"
#include "ActionCard.cpp"

class StartStack : AnimalCard {
protected:
	std::deque<AnimalCard> startStack;
public:
	friend StartStack& operator += (std::shared_ptr<ActionCard> a) {
		startStack.push_front(a);
		return startStack;
	}

	friend StartStack& operator -= (std::shared_ptr<ActionCard> a) {
		startStack.push_back(a);
		return startStack;
	}
	/*
	std::shared_ptr<StartCard> getStartCard() {
	std::cout << "";
	}*/
};