#pragma once
#ifndef STARTSTACK_H
#define STARTSTACK_H
#include "ActionCard.h"
#include "Split.h"
#include <iostream>
#include <memory>

class StartStack : AnimalCard
{
	
public:
	StartStack& operator += (std::shared_ptr<ActionCard>);
	StartStack& operator -= (std::shared_ptr<ActionCard>);
	std::shared_ptr<StartCard> getStartCard();

};

#endif