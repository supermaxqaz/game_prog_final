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
#include <stdio.h>
#include <iostream>
#include "library_framework.h"
#include "definitions.h"

using namespace std;

//Draws the board to the console
void drawBoard(gs_tictactoe const game)
{
   //Checks the height of the board
   for (int i = 0; i < GS_TICTACTOE_BOARD_HEIGHT; i++)
   {
      //Checks the width of the board
      for (int j = 0; j < GS_TICTACTOE_BOARD_WIDTH; j++)
      {
         //Places O in chosen spot
         if (gs_tictactoe_getSpaceState(game, j, i) == 1)
         {
            cout << "O ";
         }
         //Places X in chosen spot
         else if (gs_tictactoe_getSpaceState(game, j, i) == 2)
         {
            cout << "X ";
         }
         //Marks any empty spots with "-"
         else
         {
            cout << "- ";
         }
      }
      cout << endl;
   }
}
//Asks user for input based on row and column
void chooseSpot(gs_tictactoe game, gs_tictactoe_space_state player, int& playerColumn, int& playerRow)
{
   cout << "Player " << player << "'s turn" << endl;
   cout << "Which column would you like to place your piece? ";
   cin >> playerColumn;
   playerColumn--;
   cout << "Which row would you like to place your piece? ";
   cin >> playerRow;
   playerRow--;

   //Checks to make sure location chosen is valid
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

//Says hello to Dan
void hello()
{
   cout << "Hello Dan" << endl;
}


