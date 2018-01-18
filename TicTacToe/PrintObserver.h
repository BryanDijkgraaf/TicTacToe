#pragma once
#include "Observer.h"


class PrintObserver : public Observer
{
public:
	void update(Subject &s);
	//void printBoard(Subject &s);
};