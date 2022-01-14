#include <stdio.h>
#include <stdlib.h>
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

void instrucPrompt() { //instruction prompt for player when game started
    system("setterm -bold on");
    blue();
    printf("\n\t  TIC TAC TOE\n\n");
    printf("   Player 1 - X | Player 2 - O \n\n");
    system("setterm -bold off");
    printf("Please Enter Number Within 1-9 to play \n");
    printf("Tic Tac Toe as per sample below:\n\n");
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
    //printf("Enter move by player \n");
    system("setterm -bold on");
    cyan();
    printf("\t    |     |    \n");
    printf("\t  %c |  %c  | %c \n", grid[1], grid[2], grid[3]);
    printf("\t----------------\n");
    printf("\t  %c |  %c  | %c \n", grid[4], grid[5], grid[6]);
    printf("\t----------------\n");
    printf("\t  %c |  %c  | %c \n", grid[7], grid[8], grid[9]);
    printf("\t    |     |    \n");
    printf("\n");
    system("setterm -bold off");

} 

int playerMove(int player) { //function to let player enter moves
    int m;
    printf("Player %d, please enter your move: ", (player-1)%2+1);
    scanf("%d", &m);
    return m;
}

int play(int m, char *grid, int player) { //function to label in their respective grids when player enters a move
    // int m;
    // int player = 1;
    int count = 0;
    char lab; //label
        player = (player % 2) ? 1:2; //check if its player 1 or 2
        if (player == 1) lab = 'X'; //if player is 1, label is 'X'
        else if (player == 2) lab = 'O'; //if player is 2, label is 'O'

            if (m==1 && grid[1]==' ') grid[1] = lab;
            else if (m==2 && grid[2]==' ') grid[2] = lab;
            else if (m==3 && grid[3]==' ') grid[3] = lab;
            else if (m==4 && grid[4]==' ') grid[4] = lab;
            else if (m==5 && grid[5]==' ') grid[5] = lab;
            else if (m==6 && grid[6]==' ') grid[6] = lab;
            else if (m==7 && grid[7]==' ') grid[7] = lab;
            else if (m==8 && grid[8]==' ') grid[8] = lab;
            else if (m==9 && grid[9]==' ') grid[9] = lab;

            else {
                system("setterm -bold on");
                red();
                printf("\n\t  Invalid move\n\n");
                system("setterm -bold off");
                count = -1;
        }
    return count;
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
    // int player1=0, player2=1;
    // int move[9];
    char grid[gridSize];
    char position = '1';
    int m; //numbers selected by player
    int player =1; //set first player as 1
    int count; //check if the value enter is repetitive or invalid

    instrucPrompt(); //calling instruction prompt
    initialize(grid, position); //initialize grid by filling grid array with 1-9
    printGrid(grid); //calling printGrid function as user prompt
    setEmpty(grid); //set the grid empty to prepare to start the game
    //printGrid(grid); //check if grid is empty

    for (int i=1; i<gridSize; i++) {
        m = playerMove(player); //return player input as m
        int count = play(m, grid, player); //parse player input into play function to iterate and fill grid array
        player++; //continue adding player
        if (count == -1) { //if player moves is invalid, player-- and i-- hence create an infinity loop until player move is legal
            player--;
            i--;
        }
        printGrid(grid); //calling printGrid function to print the grid after player move is legal and moves are stored
        int win = checkWin(grid); //store value returned from checkWin function as win
        if (win==1) { //check if player has won, exit if true
            system("setterm -bold on");
            yellow();
            printf("\t Player %d WON!\n\n", player%2+1);
            system("setterm -bold off");
            exit(0);
        }
        //if neither players win and there isn't empty spaces left in the grid, game is tie
        else if (grid[1] != ' ' && grid[2] != ' ' && grid[3] != ' ' && grid[4] != ' ' && grid[5] != ' ' && grid[6] != ' ' && grid[7] != ' ' && grid[8] != ' ' && grid[9] != ' ') {
            system("setterm -bold on");
            green();
            printf("\t     DRAW\n\n");
            system("setterm -bold off");
        }
    }
}