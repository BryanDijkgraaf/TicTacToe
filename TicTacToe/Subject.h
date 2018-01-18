#pragma once

#include "list"
#include "string"
#include "Observer.h"
#include "Board.h"


class Subject
{
	typedef std::list<Observer*>::iterator iterator;

private:
	Board board;
	std::list<Observer*> observers;
	std::string name;

public:
	Subject();
	void add_observer(Observer&);
	void notify();
	void startGame();
	void set_turn();
	void set_name(std::string);
	std::string get_name();
	std::string * get_space();	
	char get_turn();
	bool get_running();
	bool get_won();
	int get_moveCount();
};

