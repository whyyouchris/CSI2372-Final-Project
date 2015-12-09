#include "AnimalCard.cpp"

class NoSplit : public AnimalCard {
public:
	NoSplit(char a) {
		orientation = UP;
		evenOdd = EVEN;
		animals[0][0] = a;
		animals[0][1] = a;
		animals[1][0] = a;
		animals[1][1] = a;
	}
};

class Joker : NoSplit {
	Joker() : NoSplit('j') {
	}
};

class StartCard : NoSplit {
	StartCard() : NoSplit('c') {
	}
};

class SplitTwo :AnimalCard {
public:
	SplitTwo(char a, char b, Split hv) {//left and top by default
		orientation = UP;
		evenOdd = EVEN;
		split = hv;
		if (hv == HORIZONTAL) {
			animals[0][0] = a;
			animals[0][1] = a;
			animals[1][0] = b;
			animals[1][1] = b;
		}
		else if (hv == VERTICAL) {
			animals[0][0] = a;
			animals[0][1] = b;
			animals[1][0] = a;
			animals[1][1] = b;
		}
	}
};

class SplitThree :AnimalCard {
public:
	SplitThree(char a, char b, char c, Split hv) {//left and top by default
		orientation = UP;
		evenOdd = EVEN;
		split = hv;
		if (hv == HORIZONTAL) {
			animals[0][0] = a;
			animals[0][1] = a;
			animals[1][0] = b;
			animals[1][1] = c;
		}
		else if (hv == VERTICAL) {
			animals[0][0] = a;
			animals[0][1] = b;
			animals[1][0] = a;
			animals[1][1] = c;
		}
	}
};

class SplitFour :AnimalCard {
public:
	SplitFour(char TL, char TR, char BL, char BR) {
		orientation = UP;
		evenOdd = EVEN;
		animals[0][0] = TL;
		animals[0][1] = TR;
		animals[1][0] = BL;
		animals[1][1] = BR;
	}
};
