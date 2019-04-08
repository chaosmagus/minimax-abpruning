#ifndef gamestatus_hpp
#define gamestatus_hpp


class gameStatus 	
{ 
private:
  long * gameData;

public: 
  gameStatus();
  long * gameBoard[6];
  long currentTurn;
  int player1Score;
  int player2Score;
  int pieceCount;
  FILE *gameFile;
  double utilityValue;


  gameStatus(const gameStatus &g){
    gameData = new long[42];
    memcpy(gameData, g.gameData, 42*sizeof(*gameData));
    gameBoard[0] = &(gameData[0]);
    gameBoard[1] = &(gameData[7]);
    gameBoard[2] = &(gameData[14]);
    gameBoard[3] = &(gameData[21]);
    gameBoard[4] = &(gameData[28]);
    gameBoard[5] = &(gameData[35]);
    currentTurn = g.currentTurn;
    player1Score = g.player1Score;
    player2Score = g.player2Score;
    pieceCount = g.pieceCount;
    //gameFile = g.gameFile;
    utilityValue = g.utilityValue;
    }


 // gameStatus& operator=(const gameStatus& rhs) {};

  ~gameStatus()
  {
    delete [] gameData;
  }
};

#endif 
