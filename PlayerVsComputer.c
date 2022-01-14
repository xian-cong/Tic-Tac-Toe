#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define gridSize 10 //grid size 10

void cyan() { //function to print cyan color in terminal
  printf("\033[1;36m");
}

void blue() { //function to print blue color in terminal
  printf("\033[1;34m");
}

void yellow() { //function to print yellow color in terminal
    printf("\033[1;33m");
}

void green() { //function to print green color in terminal
    printf("\033[1;32m");
}

void red() { //function to print red color in terminal
    printf("\033[1;31m");
}

void initialize(char *grid, char position) { //function to initialize grid for tic tac toe and insert number as user prompt
    for (int i=1;i<gridSize;i++) { //for loop to to insert 1 to 9 into grid as user prompt
        grid[i]=position;
        position++;
    }
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

char instrucPrompt(char *grid, char position){ //function for player to choose between smart or random AI and instruction prompt
    system("setterm -bold on");
    blue();
    printf("\n\t   TIC TAC TOE\n\n");
    printf("   Player 1 : O | Computer : X \n\n");
    system("setterm -bold off");
    printf("Please Enter Number Within 1-9 to play \n");
    printf("Tic Tac Toe as per sample below:\n\n");

    initialize(grid, position); 
    printGrid(grid);
    setEmpty(grid);
    //printGrid(grid); //check if grid is empty

    char choice;
    printf("\nSelect between 's' or 'r' to choose\ntypes of AI you want to play with:\n\n");
    system("setterm -bold on");
    blue();
    printf("   Smart AI - s | Random AI - r\n");
    system("setterm -bold off");
    scanf("%c", &choice);
    switch(choice) {
        case 'r':
            system("setterm -bold on");
            yellow();
            printf("\tRandom AI selected\n");
            system("setterm -bold off");
            return 'r'; //return r if r is selected
            break;
        case 's':
            system("setterm -bold on");
            yellow();
            printf("\tSmart AI selected\n");
            system("setterm -bold off");
            return 's'; //return s if s is selected
            break;
        default:
            system("setterm -bold on");
            red();
            printf("Error, please enter 's' or 'r' only!\n");
            system("setterm -bold off");
            exit(0);
    }
}

int playerSelection() { //function for player to select who to start first
    int selection;
    while(1) {//loop to check if start from player or from computer
        printf("Select between 1 or 2 to choose\n");
        printf("who to start the game: \n\n");
        system("setterm -bold on");
        blue();
        printf("    Player - 1 | Computer - 2\n");
        system("setterm -bold off");
        scanf("%d", &selection);
        switch(selection) {
            case 1:
                return selection;
                break;
            case 2:
                return selection;
                break;
            default:
            system("setterm -bold on");
            red();
            printf("Error, please enter 1 or 2 only!\n");
            system("setterm -bold off");
        }
    }
    printf("\n");
}

int playerMove(int player) { //function to let player enter moves
    int m;
    printf("Player %d, please enter your move: ", player);
    scanf("%d", &m);
    return m;
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
int AI(char *grid, char XO) { //function to check whether to attack or block by checking all iterations
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

int playerTurn(char XO, char *grid, int *store, int player) { //function to check player value and store into temperory store array and grid to be printed out
    int m=playerMove(player); //returns user input from playerMove function to check if its legal moves
    if (m<10 && m>0 && m!=store[m]) { //check if its legal moves
        store[m]=m; //if true then store user input into temporary store array
        grid[m]=XO; //if true then print user input into grid
    }
    else {
        system("setterm -bold on");
        red();
        printf("\n\t  Invalid move\n\n");
        system("setterm -bold off");
        playerTurn('O', grid, store, player); //if false, loop the function again until its true
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

int computerAI(char XO, char *grid, int *store) { //function to call SmartAI
    int attack=AI(grid, 'X'); //since computer is 'X' by default, it will loop through the AI algorithm to check if it can win or not and return values as attack
    int block=AI(grid, 'O'); //it will loop through the AI algorithm to check if it can block or not
    if (attack!=-2) { //if there is condition satisfied, the computer will attack and win the game first when it returns value not equals to -2
        grid[attack]='X'; //place 'X' to attack and win the game
        store[attack]=attack; //store value into temperory store function to match with player input hence it will only play without overwritting the player
    }
    else if (block!=-2) { //if there is no winning condition first, the computer will look for blocking condition and block if it satisfied the condtion and return value which is not equals to -2
        grid[block]='X'; //place 'X' to block to prevent player from winning
        store[block]=block; //store value into temperory store function to match with player input hence it will only play without overwritting the player
    }
    else{
        computerRand('X', grid, store); //if value returns is -2, it falls back to randomAI and chooses legal move.
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

int main() {
    char grid[gridSize];
    /*store[] is a temperory store array which will not be printed out, it is being use to store values return by computer
    and player hence the values does not mix up and player cannot overwrite computer's moves(vice versa)*/
    int store[]={10,10,10,10,10,10,10,10,10,10}; 
    char position = '1'; //value to be used in initialize function which is the user prompt function
    char XO; //switch between XO for each player turn
    int m; //numbers selected by player
    int player = 1; //set first player as 1
    int i=1;//loop for 9 times if no one win the game

    srand(clock()); //get random seed from clock function hence its randomized everytime
    
    char choice = instrucPrompt(grid, position); //calling smart or random function for player to choose difficulty
    int selection = playerSelection(); //calling instruction prompt
    
    while(i<gridSize){
        if (choice == 's') { //loop to choose smart AI
            if (selection%2 == 0){ //if 2 is selected, the computer will start first since the remainder is 0 if div by 2
                printf("Computer's turn: \n");
                computerAI('X',grid,store);
                XO='X';
            }
        else{
                playerTurn('O',grid,store, player);
                XO='O';
            }
        //Will exit the loop if check_Win function return 1.    
        printGrid(grid); 
        printf("\n"); 
        }
        else if (choice == 'r') { //loop to choose random AI
            if (selection%2 == 0){ //if 2 is selected, the computer will start first since the remainder is 0 if div by 2
                printf("Computer's turn: \n");
                computerRand('X',grid,store);
                XO='X';
            }
            else{
                playerTurn('O',grid,store, player);
                XO='O';
            }
        //Will exit the loop if check_Win function return 1.      
        printGrid(grid); 
        printf("\n");
        }

        if (checkWin(grid)){ //go through checkWin function to see if player has won, if its true, exit the game
            i=-1;
            system("setterm -bold on");
            yellow();
            printf("\tPlayer %c has won.\n\n",XO);
            system("setterm -bold off");
            exit(0);
        } 
        else{ //if checkWin function is false, continue to loop
            selection++;
            i++;
        }
    }
    if (i != -1) { //Draw if no one win the game
        system("setterm -bold on");
        green();
        printf("\t     DRAW\n\n");
        system("setterm -bold off");
    }
}