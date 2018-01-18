#include "stdafx.h"
#include <string>
#include <list>
#include "Subject.h"
#include "Board.h"

using namespace std;

Subject::Subject() {
	board = Board();
}

void Subject::add_observer(Observer& _observer) {
	observers.push_back(&_observer);
}

void Subject::notify() {
	for (iterator it = observers.begin(); it != observers.end(); it++) {
		(*it)->update(*this);
	}
}

void Subject::startGame() {
	board.handleInput();
}

void Subject::set_name(string s) {
	name = s;
	notify();		
}

void Subject::set_turn() {
	board.turn = 'x';
	}

string Subject::get_name() {
	return name;	
}

string * Subject::get_space() {
	return board.space;		
}

char Subject::get_turn() {
	return board.turn;
	}

bool Subject::get_running() {
	return board.running;
}

bool Subject::get_won() {
	return board.won;
}

int Subject::get_moveCount() {
	return board.moveCount;
}