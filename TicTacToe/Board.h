#pragma once
#include "string"
class Board
{
private:
	
	std::string place;
public:
	Board();
	void changeField(std::string);
	bool winDetection();
	bool inputCorrect(std::string);
	void handleInput();
	void switchTurn();
	std::string space[64];
	char turn= 'X';
	int moveCount = 0;
	bool running = true;
	bool won = false;
};

