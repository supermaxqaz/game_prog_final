/*
Author: Maxwell & Lindsey
Class: GPR-100-02
Assignment: Framework Final
Date Assigned: 3/24/2020
Due Date: 4/3/2020 at 5:00

Description:
   We make a tic tac toe game and seperated its display funtions into a seperate library.

Certification of Authenticity:
   I certify that this is entirely my own work, except where I have given
   fully-documented references to the work of others. I understand the
   definition and consequences of plagiarism and acknowledge that the assessor
   of this assignment may, for the purpose of assessing this assignment:
      -Reproduce this assignment and provide a copy to another member of
      academic staff; and/or
      -Communicate a copy of this assignment to a plagiarism checking
      service (which may then retain a copy of this assignment on its
      database for the purpose of future plagiarism checking)
*/
#include "library_framework.h"
#include "definitions.h"

using namespace std;

int launchTicTacToe();
#include <stdio.h>
#include <iostream>

using namespace std;

//Checks if the game is a tie
bool tieState(gs_tictactoe const game)
{
	for (int i = 0; i < GS_TICTACTOE_BOARD_HEIGHT; i++)
	{
		for (int j = 0; j < GS_TICTACTOE_BOARD_WIDTH; j++)
		{
			if (gs_tictactoe_getSpaceState(game, j, i) == gs_tictactoe_space_open)
			{
				return false;
			}
		}
	}
	return true;
}

//Launches the project
int launchTicTacToe()
{
	gs_tictactoe game;

	char playAgain = 'y';

	do {
		gs_tictactoe_reset(game);

		gs_tictactoe_space_state player = gs_tictactoe_space_o;
		bool playerWon = false;
		gs_tictactoe_space_state winner = gs_tictactoe_space_invalid;
		bool tie = false;
		int playerRow, playerColumn;
	
      //Waits for a player to either win or tie before resetting the board
		while (!playerWon && !tie)
		{
			drawBoard(game);

         chooseSpot(game, player, playerColumn, playerRow);

			game[playerColumn][playerRow] = player;
         
         //Allows for each player to choose their row and column
			for (int i = 0; i < GS_TICTACTOE_BOARD_WIDTH; i++)
			{
				if (game[0][i] == game[1][i] && game[1][i] == game[2][i] && game[0][i] != gs_tictactoe_space_open)
				{
					playerWon = true;
					winner = player;
				}
				else if (game[i][0] == game[i][1] && game[i][1] == game[i][2] && game[i][0] != gs_tictactoe_space_open)
				{
					playerWon = true;
					winner = player;
				}
			}
			if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[0][0] != gs_tictactoe_space_open)
			{
				playerWon = true;
				winner = player;
			}
			else if (game[2][0] == game[1][1] && game[1][1] == game[0][2] && game[2][0] != gs_tictactoe_space_open)
			{
				playerWon = true;
				winner = player;
			}

			tie = tieState(game);

			if (player == gs_tictactoe_space_o)
			{
				player = gs_tictactoe_space_x;
			}
			else if (player == gs_tictactoe_space_x)
			{
				player = gs_tictactoe_space_o;
			}
		}

		drawBoard(game);

      //Prompts the user with either their victory or tiedgame. Then asks if they want to play again.
		if (playerWon)
		{
			cout << "Congratulations! Player " << winner << " wins!" << endl << endl;
		}
		else if (tie)
		{
			cout << "The game was a tie!" << endl << endl;
		}

		cout << "Would you like to play again? (y/n) ";
		cin >> playAgain;
		playAgain = tolower(playAgain);

	} while (playAgain == 'y');

	return 0;
}


//-----------------------------------------------------------------------------


int main()
{
   hello();

   launchTicTacToe();

   return 0;
}