#include <stdio.h>
#include <iostream>
#include "library_framework.h"
#include "definitions.h"

using namespace std;

void drawBoard(gs_tictactoe const game)
{
   for (int i = 0; i < GS_TICTACTOE_BOARD_HEIGHT; i++)
   {
      for (int j = 0; j < GS_TICTACTOE_BOARD_WIDTH; j++)
      {
         if (gs_tictactoe_getSpaceState(game, j, i) == 1)
         {
            cout << "O ";
         }
         else if (gs_tictactoe_getSpaceState(game, j, i) == 2)
         {
            cout << "X ";
         }
         else
         {
            cout << "- ";
         }
      }
      cout << endl;
   }
}
void chooseSpot(gs_tictactoe game, gs_tictactoe_space_state player, int& playerColumn, int& playerRow)
{
   cout << "Player " << player << "'s turn" << endl;
   cout << "Which column would you like to place your piece? ";
   cin >> playerColumn;
   playerColumn--;
   cout << "Which row would you like to place your piece? ";
   cin >> playerRow;
   playerRow--;

   while (gs_tictactoe_getSpaceState(game, playerColumn, playerRow) != gs_tictactoe_space_open)
   {
      cout << "That is not a valid space" << endl;
      cout << "Which row would you like to place your piece? ";
      cin >> playerRow;
      playerRow--;
      cout << "Which column would you like to place your piece? ";
      cin >> playerColumn;
      playerColumn--;
   }
}

void hello()
{
   cout << "Hello Dan" << endl;
}


