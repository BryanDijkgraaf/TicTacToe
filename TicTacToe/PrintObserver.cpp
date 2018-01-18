#include "stdafx.h"
#include "PrintObserver.h"
#include "Subject.h"
#include <iostream>

using namespace std;

void PrintObserver::update(Subject &s) {
	string * space = 0;
	char turn = 0;

	space = s.get_space();
	turn = s.get_turn();
	system("CLS");
	int k, p;

	for (int o = 0; o < 4; o++)
	{
		p = o * 4;
		for (int j = 0; j < 4; j++)
		{
			k = j * 16;
			for (int i = 0; i < 4; i++)
			{
				int kip = k + i + p;
				string line = space[kip];

				if (line.size() == 1)
					line += "  ";
				else if (line.size() == 2)
					line += " ";

				if (i == 0)
					cout << "   " << line << " ";
				else
					cout << "|  " << line << " ";

			}
		}
		if (o != 3)
			cout << "\n" << "  __________________________  __________________________  __________________________  __________________________" << "\n";
	}
	cout << "\n";
	if (s.get_won())
		cout << endl << endl << "Congratulations you won!" << endl;
	else
		cout << endl << endl << "Player " << turn << " Where would you like to put your mark? " << endl;
}