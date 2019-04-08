#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#include "gameStatus.hpp"
 #include "gameStatus.hpp" 

gameStatus::gameStatus(){
    gameData = new long[42];
    gameBoard[0] = &(gameData[0]);
    gameBoard[1] = &(gameData[7]);
    gameBoard[2] = &(gameData[14]);
    gameBoard[3] = &(gameData[21]);
    gameBoard[4] = &(gameData[28]);
    gameBoard[5] = &(gameData[35]);

    int i;
    for (i = 0; i < 42; i++)
    {
      gameData[i] = 0;
    }

    currentTurn = 1;
    player1Score = 0;
    player2Score = 0;
    pieceCount = 0;
    gameFile = 0;
    utilityValue = 0;
  }

