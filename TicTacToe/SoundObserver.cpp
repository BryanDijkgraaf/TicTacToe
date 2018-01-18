#include "stdafx.h"
#include "SoundObserver.h"
#include "Subject.h"
#include "iostream"
#include <Windows.h>
#include <MMSystem.h>


using namespace std;

void SoundObserver::update(Subject &s) {
	//cout << " times updated." << endl;
	if (s.get_won())
		PlaySound(TEXT("Winning.wav"), NULL, SND_FILENAME);
	else if (s.get_moveCount()!= previousMoveCount)
		PlaySound(TEXT("NextPlayer.wav"), NULL, SND_FILENAME);
}