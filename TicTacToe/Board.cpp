#include "stdafx.h"
#include "Board.h"
#include "Subject.h"
#include <iostream>
#include <cctype>

using namespace std;

Board::Board()
{
	string letter[] = { "A", "B", "C", "D" };

	for (int i = 0; i < 64; i++)	// Fill te board with some values
	{
		cout << "                                            " << endl;
		int y = i / 16;
		space[i] = letter[(i / 16)] + to_string(i - (y * 16));
	}
}

void Board::switchTurn()
{
	if (turn == 'X')	//Switch the player
		turn = 'O';
	else if (turn == 'O')
		turn = 'X';
	moveCount++;
}

void Board::changeField(string place)
{
	for (int i = 0; i < 64; i++)
		if (place == space[i])	// Give the player his space
			space[i] = turn;

	if (winDetection()) { // If game won
		won = true;
		running = false;
	}
	else // Else game is still going strong!
		switchTurn();


}

bool Board::inputCorrect(string place) {
	if (place.length() != 1) {		//Check of the space is correct and free
		for (int i = 0; i < 64; i++)
			if (place == space[i])
				return true;
	}
	return false;
}

void Board::handleInput() {
	bool incorrect = true;
	string place;

	while (incorrect) {
		cin >> place;

		place[0] = toupper(place[0]);
		string input = place;

		incorrect = !inputCorrect(place);

		if (incorrect)
			cout << input << " - is not a valid location" << endl;
	}

	changeField(place);

}

bool Board::winDetection()
{
	bool win = false;
	for (int l = 0; l < 64; l++)
	{
		if (l % 4 == 0)
			if (space[l] == space[l + 1] && space[l] == space[l + 2] && space[l] == space[l + 3])			//horizontal from front view
				win = true;

		if (l > -1 && l < 4 || l>15 && l < 20 || l>31 && l < 36 || l>47 && l < 52)							//vertical from front view
			if (space[l] == space[l + 4] && space[l] == space[l + 8] && space[l] == space[l + 12])
				win = true;

		if (l > -1 && l < 16)
			if (space[l] == space[l + 16] && space[l] == space[l + 32] && space[l] == space[l + 48])		//depth from front view
				win = true;

		if (l > -1 && l < 4)
			if (space[l] == space[l + 20] && space[l] == space[l + 40] && space[l] == space[l + 56])		//crosses from front view above to rear under
				win = true;

		if (l > 11 && l < 16)
			if (space[l] == space[l + 12] && space[l] == space[l + 24] && space[l] == space[l + 36])		//crosses from front view above to rear under
				win = true;

		if (l == 0 || l == 16 || l == 32 || l == 48)														//crosses from front view
			if ((space[l] == space[l + 5] && space[l] == space[l + 10] && space[l] == space[l + 15]) ||
				(space[l + 3] == space[l + 6] && space[l] == space[l + 9] && space[l] == space[l + 12]))
				win = true;

		if (win)
			return win;
	}
	if ((space[0] == space[21] && space[0] == space[42] && space[0] == space[63]) ||						//crosses through the cube
		(space[3] == space[22] && space[3] == space[41] && space[3] == space[60]) ||
		(space[12] == space[25] && space[12] == space[38] && space[12] == space[51]) ||
		(space[15] == space[26] && space[15] == space[37] && space[15] == space[48]))
		win = true;

	return win;
}