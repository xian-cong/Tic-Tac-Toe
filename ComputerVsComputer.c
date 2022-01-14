#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define gridSize 10 //grid size 10

void cyan() { //function to print cyan color in terminal
  printf("\033[1;36m\n");
}

void blue() { //function to print blue color in terminal
  printf("\033[1;34m\n");
}

void yellow() { //function to print yellow color in terminal
    printf("\033[1;33m\n");
}

void green() { //function to print green color in terminal
    printf("\033[1;32m\n");
}

void red() { //function to print red color in terminal
    printf("\033[1;31m\n");
}

void setEmpty(char *grid) { //function to clear the grid to prepare for game
    for (int i=1;i<gridSize;i++) { //for loop to replace numbers in grid with empty spaces
        grid[i]=' ';
    }
}

void printGrid(char *grid) { //function to print grid for tic tac toe
    system("setterm -bold on");
    cyan();
    printf("\t     |     |    \n");
    printf("\t   %c |  %c  | %c \n", grid[1], grid[2], grid[3]);
    printf("\t ----------------\n");
    printf("\t   %c |  %c  | %c \n", grid[4], grid[5], grid[6]);
    printf("\t ----------------\n");
    printf("\t   %c |  %c  | %c \n", grid[7], grid[8], grid[9]);
    printf("\t     |     |    \n");
    printf("\n");
    system("setterm -bold off");
} 

int randomNum() { //function to generate random number
    int random = 1 + (9.0*rand())/(RAND_MAX+1.0); //generate with MSB formula
    return random;
}

/*
Reactionary AI: 
AI will block the opponents three in a row, or take any three in a row it can.
Otherwise it will choose random moves. Below are possible moves that the AI can attack or block.
The AI will be called twice: first time to check whether it can win the game, second time to check whether it can block.
It will return -2 if there isn't any condition satisfied.
If the AI check the first condition and find the same with second condition which is third condition black spaces, 
it will return X or O depends whether to attack or block.
*/
int AI(char *grid, char XO) { //function computer AI to check whether to attack or block
    if ((grid[1] == grid[2]) && grid[3]==' ' && grid[1]==XO) return 3;
    else if ((grid[4] == grid[5]) && grid[6]==' ' && grid[4]==XO) return 6;
    else if ((grid[7] == grid[8]) && grid[9]==' ' && grid[7]==XO) return 9;

    else if ((grid[2] == grid[3]) && grid[1]==' ' && grid[2]==XO) return 1;
    else if ((grid[5] == grid[6]) && grid[4]==' ' && grid[5]==XO) return 4;
    else if ((grid[8] == grid[9]) && grid[7]==' ' && grid[8]==XO) return 7;

    else if ((grid[1] == grid[3]) && grid[2]==' ' && grid[1]==XO) return 2;
    else if ((grid[4] == grid[6]) && grid[5]==' ' && grid[4]==XO) return 5;
    else if ((grid[7] == grid[9]) && grid[8]==' ' && grid[7]==XO) return 8;

    else if ((grid[1] == grid[4]) && grid[7]==' ' && grid[1]==XO) return 7;
    else if ((grid[2] == grid[5]) && grid[8]==' ' && grid[2]==XO) return 8;
    else if ((grid[3] == grid[6]) && grid[9]==' ' && grid[3]==XO) return 9;

    else if ((grid[4] == grid[7]) && grid[1]==' ' && grid[4]==XO) return 1;
    else if ((grid[5] == grid[8]) && grid[2]==' ' && grid[5]==XO) return 2;
    else if ((grid[6] == grid[9]) && grid[3]==' ' && grid[6]==XO) return 3;

    else if ((grid[1] == grid[7]) && grid[4]==' ' && grid[1]==XO) return 4;
    else if ((grid[2] == grid[8]) && grid[5]==' ' && grid[2]==XO) return 5;
    else if ((grid[3] == grid[9]) && grid[6]==' ' && grid[3]==XO) return 6;

    else if ((grid[1] == grid[5]) && grid[9]==' ' && grid[1]==XO) return 9;
    else if ((grid[5] == grid[9]) && grid[1]==' ' && grid[5]==XO) return 1;
    else if ((grid[1] == grid[9]) && grid[5]==' ' && grid[1]==XO) return 5;

    else if ((grid[3] == grid[5]) && grid[7]==' ' && grid[3]==XO) return 7;
    else if ((grid[5] == grid[7]) && grid[3]==' ' && grid[5]==XO) return 3;
    else if ((grid[3] == grid[7]) && grid[5]==' ' && grid[3]==XO) return 5;
    else return -2;
}

int computerAI(char XO, char *grid, int *store) { //function to call SmartAI
  int nonLegal = 1; //check if the move is legal and satisfy or not
  char attackBlock[2]; //array to check if computer need to attack or block
  if(XO == 'X') { //check if computer is 'X' or 'O'
    attackBlock[0]='X'; //attack[0] is used for attack
    attackBlock[1]='O'; //attack[1] is used for block
  }
  else {
    attackBlock[0]='O';
    attackBlock[1]='X';
  }
  int attack=AI(grid, attackBlock[0]); //Computer will loop through the AI algorithm to check if it can win or not and return values as attack
  int block=AI(grid, attackBlock[1]); //it will loop through the AI algorithm to check if it can block or not
  if (attack!=-2) { //if there is condition satisfied, the computer will attack and win the game first when it returns value not equals to -2
    grid[attack]=XO; //place 'X' or 'O' depends on computers to attack and win the game
    store[attack]=attack; //store value into temperory store function to match with player input hence it will only play without overwritting the other computer
  }
  else if (block!=-2) { //if there is no winning condition first, the computer will look for blocking condition and block if it satisfied the condtion and return value which is not equals to -2
    grid[block]=XO; //place 'X' or 'O' depends on computers to block to prevent player from winning
    store[block]=block; //store value into temperory store function to match with player input hence it will only play without overwritting the player
  }
  else{ //if value returns is -2, it falls back to randomAI and chooses legal move.
    while(nonLegal) { //infinity loop to generate random values if moves are not legal
      int random=randomNum(); //store it as random
      if (store[random]==random) { //check if it is legal moves, if there are things stored in the temperory store array, it will loop again and get new random values
        nonLegal=1; //generate new random values
      }
      else{ //if it is legal moves and the temporary store array is default value(10), it will store 'X' into grid and store value generated into temprorary store array
        grid[random]=XO; //store into grid if it's legal moves
        store[random]=random; //replace default value with random value generated 
        nonLegal=0; //break the infinity loop
      }
    }
  }
}

void computerRand(char XO, char *grid, int *store) { //function to generate randomAI
  int nonLegal=1; //check if the move is legal and satisfy or not
    while(nonLegal){ //infinity loop to generate random values if moves are not legal
      int random = randomNum(); //store it as random
      if (store[random]==random){ //check if it is legal moves, if there are things stored in the temperory store array, it will loop again and get new random values
        nonLegal=1; //generate new random values
      }
      else{ //if it is legal moves and the temporary store array is default value(10), it will store 'X' into grid and store value generated into temprorary store array
        grid[random]=XO; //store into grid if it's legal moves
        store[random]=random; //replace default value with random value generated 
        nonLegal=0; //break the infinity loop
      }
    }
}

int checkWin(char *grid) { //function to check win
    char temp[gridSize]; //temperory store array
    char rand='@'; //temperory store random things inside temp[i] but not printed so game does not immediately end when its started with all ' '
    for (int i=1;i<gridSize;i++) {
        if (grid[i] == ' ') temp[i]=rand; //temporary store random items hence the game will not check as win if it detects empty spaces
        else temp[i]=grid[i];
        rand++;
    }
    /*
    function returns 1 if win else continue
    */
    //check horizontal
    if (temp[1] == temp[2] && temp[2] == temp[3]) return 1;
    else if (temp[4] == temp[5] && temp[5] == temp[6]) return 1;
    else if (temp[7] == temp[8] && temp[8] == temp[9]) return 1;
    //check vertical
    else if (temp[1] == temp[4] && temp[4] == temp[7]) return 1;
    else if (temp[2] == temp[5] && temp[5] == temp[8]) return 1;
    else if (temp[3] == temp[6] && temp[6] == temp[9]) return 1;
    //check diagonal
    else if (temp[1] == temp[5] && temp[5] == temp[9]) return 1;
    else if (temp[3] == temp[5] && temp[5] == temp[7]) return 1;
    else return 0;
}

void typeOfPlayers(int *condition, int types){ //function to loop over different types of computers(i.e. smart and random)
  int i=1;  //variable to iterate over the loop.
  char XO; //switch between XO for each player turn
  int store[]={10,10,10,10,10,10,10,10,10,10};//array use to check user input.
  char grid[gridSize];//array use to store tic tae toe board.

  setEmpty(grid);//clear the tic-tac-toe board with white space.

  int computer=1;//set which computer plays first, (O) plays first

  while(i<gridSize){
    if (computer%2 == 0){ //loop between computer 1 and 2
      switch(types) { //loop from main from 1 to 3
        case 1: //when go through the first iteration in the loop, smartAI is chosen
          computerAI('X',grid,store); 
          // printGrid(grid); //check if computer plays correctly
          break;
        case 2: //when go through the second iteration in the loop, smartAI is chosen
          computerAI('X',grid,store); 
          break;
        case 3: //when go through the third iteration in the loop, randomAI is chosen
          computerRand('X',grid,store);
          break;
      }
      XO='X'; //computer 1-'X'
    }
    else{ //loop between computer 1 and 2
      switch(types) {
        case 1: //when go through the first iteration in the loop, smartAI is chosen
          computerAI('O',grid,store);  
          // printGrid(grid); //check if computer plays correctly
          break;
        case 2: //when go through the second iteration in the loop, randomAI is chosen
          computerRand('O',grid,store);
          break;
        case 3: //when go through the third iteration in the loop, randomAI is chosen
          computerRand('O',grid,store);
          break;
      }
      XO='O'; //computer 2 - 'O'
    }

      //Will exit the loop if check_Win function return 1. 
      if (checkWin(grid)){ //go through checkWin function to see if any computer has won
        i=20;
        if (XO == 'X') condition[2]++; //Player x wins the game and stored in condition[2]
        else condition[0]++; //Player o wins the game and stored in condition[0]
      } 
      else{ //if checkWin function is false, continue to loop
        computer++; 
        i++;
      }
  }
  if (i != 20){ //Draw if no one win the game
    condition[1]++;//Store tie games in condition[1]
  } 
}

void result(int types, int *condition) { //function to print results
  switch(types) {
    case 1: //result of smart vs smart
      system("setterm -bold on");
      blue();
      printf("\t\t AI vs AI\n");
      cyan();
      printf("  #P1 Wins   |    #Draws    |   #P2 Wins\n");
      printf("-------------------------------------------\n");
      printf("  %6d     |   %6d     |   %6d   \n\n", condition[0], condition[1], condition[2]);
      printf("  #P1 Losses |    #Draws    |  #P2 Losses\n");
      printf("-------------------------------------------\n");
      printf("  %6d     |   %6d     |   %6d   \n", condition[2], condition[1], condition[0]);
      system("setterm -bold off");
      break;
    
    case 2: //result of random vs smart
      system("setterm -bold on");
      blue();
      printf("\t       Random vs AI\n");
      cyan();
      printf("  #P1 Wins   |    #Draws    |   #P2 Wins\n");
      printf("-------------------------------------------\n");
      printf("  %6d     |   %6d     |   %6d   \n\n", condition[0], condition[1], condition[2]);
      printf("  #P1 Losses |    #Draws    |  #P2 Losses\n");
      printf("-------------------------------------------\n");
      printf("  %6d     |   %6d     |   %6d   \n", condition[2], condition[1], condition[0]);
      system("setterm -bold off"); 
      break;
    
    case 3: //result of random vs random
      system("setterm -bold on");
      blue();
      printf("\t     Random vs Random\n");
      cyan();
      printf("  #P1 Wins   |    #Draws    |   #P2 Wins\n");
      printf("-------------------------------------------\n");
      printf("  %6d     |   %6d     |   %6d   \n\n", condition[0], condition[1], condition[2]);
      printf("  #P1 Losses |    #Draws    |  #P2 Losses\n");
      printf("-------------------------------------------\n");
      printf("  %6d     |   %6d     |   %6d   \n", condition[2], condition[1], condition[0]);
      system("setterm -bold off");
      break;
  }
}

int main(){
  int types;//variable to store smart vs smart, smart vs random and random vs random
  for(int i=0;i<3;i++){
    int condition[]={0,0,0};//store the number of times for computer wins, draw or losses
    srand(clock()); //get random seed from clock function hence its randomized everytime
    switch(i) {
      case 0: //smart vs smart
        types=1;
        break;
      case 1: //smart vs random
        types=2;
        break;
      case 2: //random vs random
        types=3;
        break;
    }
    for(int j=0;j<10000;j++) {
      typeOfPlayers(condition,types); //iterate over 10000 times to get better accuracy of results
    }
    result(types, condition); //calling result function to print result
  }
}