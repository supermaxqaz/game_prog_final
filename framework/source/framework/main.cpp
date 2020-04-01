#include "library_framework.h"
#include "definitions.h"

using namespace std;

int launchTicTacToe();
#include <stdio.h>
#include <iostream>

using namespace std;

//-----------------------------------------------------------------------------
// DECLARATIONS



//-----------------------------------------------------------------------------
// DEFINITIONS


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

int launchTicTacToe()
{
	gs_tictactoe game; //= { 0 };

	char playAgain = 'y';

	do {
		gs_tictactoe_reset(game);

		gs_tictactoe_space_state player = gs_tictactoe_space_o;
		bool playerWon = false;
		gs_tictactoe_space_state winner = gs_tictactoe_space_invalid;
		bool tie = false;
		int playerRow, playerColumn;
	
		while (!playerWon && !tie)
		{
			drawBoard(game);

         chooseSpot(game, player, playerColumn, playerRow);

			game[playerColumn][playerRow] = player;

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