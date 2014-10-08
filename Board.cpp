#include "Board.h"
#include <iostream>
#include <string>
using namespace std;

//always rember to tell the functions what classes they are associated with for example void class::function()

Board::Board()
{
	clearBoard();
	


}

void Board::playGame()
{
	//player 1 is X and player 2 is O
	char player1 = 'X';
	char player2 = 'O';

	//sets the current player and who plays first
	char currentPlayer = player1;
	bool isDone = false;
	int x, y;

	int turn = 0;


	//main game loop
	//while the game is runnign it procceeds to constantly print the baord and recive user input until the game is closed
	while(isDone == false)
	{
		printBoard();
		x = getXCoord();
		y = getYCoord();
		//checks to see if the spot is taken by a place marker
		if (placeMarker(x, y, currentPlayer) == false)
		{
			cout << "That spots taken\n";
		}else{
			turn++;

			if (checkForVictory(currentPlayer) == true)
			{
				cout << "the game is over! " << currentPlayer << "has won\n";
				isDone = true;
			}else if(turn == 9)
			{
				cout << "the game is a tie!\n";
				isDone = true;

			}
		}


		//switches players eeach time the loop runs
		if(currentPlayer == player1)
		{
			currentPlayer = player2;

		}else{
			currentPlayer = player1;
		}


	}
	
}

void Board::printBoard()
{
	cout << endl;
	//sets the look of the board to be 3/3
	cout << " |1 2 3|\n";
	//this for loop is used to print the board 
	for (int i = 0; i < 3; i++)
	{
		cout << " -------\n";
		cout << i+1 << "|" << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "|\n";

	}
		cout << " -------\n";
}

int Board::getXCoord()
{
	//gets the x coordinates from the player
	//using in because the user enters number1-3
	bool isInputBad = true;
	int x;

	while(isInputBad == true)
	{
	cout << "Enter the X coordinate: ";
	cin >> x;
	
		if(x > 3 || x < 1)
		{
		cout << "please enter a number between 1-3";
		}else{
			isInputBad = false;
		}
	}
	return x - 1;
}

int Board::getYCoord()
{
	//gets the useres y coordinates
	int y;
	bool isInputBad = true;

		while(isInputBad == true)
		{
		cout << "Enter the Y coordinate: ";
		cin >> y;

		if (y < 1 || y > 3)
			{
			cout << "Please enter a number between 1-3";
		}else{
			isInputBad = false;

			}
		}
	
	return y - 1;

}

bool Board::placeMarker(int x, int y, char currentPlayer)
{
	//checks to see if space is avalible for input
	//uses board array with the varibles y and x to see if there is a space

	if(board[y][x] != ' ')
	{
		return false;
	}
	//if there is a space then it inputs the currentplayers marker
	board[y][x] = currentPlayer;
	return true;

}

bool Board::checkForVictory(char currentPlayer)
{
	//check the row
	for (int i = 0; i < 3; i++)
	{
		if((board[i][0] == currentPlayer) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
		{
		return true;
		}
	}
	//check colum
		for (int i = 0; i < 3; i++)
	{
		if((board[0][i] == currentPlayer) && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))
		{
			return true;

		}
	}
		//left diagonal
		if((board[0][0] == currentPlayer) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
		{
			return true;

		}

		//right diagonal
		if((board[2][0] == currentPlayer) && (board[2][0] == board[1][1]) && (board[1][1] == board[0][1]))
		{
			return true;

		}
		return false;
}

void Board::clearBoard()
{
	//clears out the board
	//for loop runs till it surpasses 3 the first for loop is for the x xcoordinates under i the second is for y under j
	//the array for spaces i and j are replaced with a blank space to reset the board
	for (int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		
		}
	}
}

