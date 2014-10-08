#include <iostream>
#include <string>
#include "Board.h"

using namespace std;

int main()
{
	char input;

	bool isDone = false;
	Board game;
	
	while(isDone == false)
	{
	game.playGame();
	cout << "would you like to play again? (Y/N) \n";
	cin >> input;

	if (input == 'N' || input == 'n')

		isDone = true;
	}

	system("PAUSE");
	return 0;
}