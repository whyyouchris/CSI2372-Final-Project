#ifndef ANIMALCARD_H_INCLUDED
#define ANIMALCARD_H_INCLUDED

#define CARDSIZE 2

class AnimalCard {
protected:
	enum Orientation { UP = 0, DOWN = 180 };
	enum Split { VERTICAL, HORIZONTAL };//direction the split will be for majority
	enum EvenOdd { EVEN, ODD, DEFAULT };
	enum CardType { B, D, H, M, W, C }; //bear,deer,hare,moose,wolf

	char animals[CARDSIZE][CARDSIZE];
	int numTypes;
	Orientation orientation;
	EvenOdd evenOdd;
	Split split;

public:
	AnimalCard();
	~AnimalCard();
	virtual void setOrientation(Orientation);
	virtual void setRow(EvenOdd);
	virtual void printRow(EvenOdd);
	virtual bool isSame(AnimalCard);
};

#endif // ANIMALCARD_H_INCLUDED
