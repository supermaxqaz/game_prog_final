#pragma once
#include "definitions.h"

void hello();

void drawBoard(gs_tictactoe const game);

void chooseSpot(gs_tictactoe game, gs_tictactoe_space_state player, int& playerColumn, int& playerRow);


