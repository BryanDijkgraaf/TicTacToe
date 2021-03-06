// TicTacToe.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <list>
#include <cctype>
#include "stdafx.h"
#include "Subject.h"
#include "Board.h"
#include "Observer.h"
#include "PrintObserver.h"
#include "SoundObserver.h"

using namespace std;


string * space = 0;

int main()
{
	Subject subject;

	subject.add_observer(*new PrintObserver);
	subject.add_observer(*new SoundObserver);
	subject.notify();

	while (!subject.get_won()) {
		subject.startGame();
		subject.notify();
	}

	system("pause");
	return 0;
}












