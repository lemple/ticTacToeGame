#pragma once
class Board
{
public:
	
	Board();

	//function that just plays game
	void playGame();

	

private:

	//this recives the coordinates from the user which is either 1-3 
	int getXCoord();
	int getYCoord();
	//this function places the marker. it checks to see if user input is true and if so places the marker. it asscoisates with int x and y and char currentPlayer
	bool placeMarker(int x, int y, char currentPlayer);

	//character varible with array with the capacity of 3 for the 3/3 board first one being the x coords second being the y's
	char board [3][3];
	//clears the board
	void clearBoard();
	//prints the baord
	void printBoard();
	//checks to see if there is 3 in a row
	bool checkForVictory(char currentPlayer);

};

