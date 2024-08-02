// c program for tic-tac-toe
// balla sravani
#include<stdio.h>

#include <stdbool.h>

void printGrid(char grid [6][6]);

void updateGame(char move,char player,char grid [6][6]);

void launchGame();

bool gameEnded(char grid[6][6]);

bool positionFlag = 1;

int main()
{
    printf("\t\t\tWELCOME!\n");

    printf("\t\t\tTIC-TAC-TOE\n");

    printf("\t\t\tBY SRAVANI\n ");

    printf("Press 's' to start the game or any other key to exit\n");

    char inputFromUser = ' ';


    scanf(" %c", &inputFromUser);

    if(inputFromUser == 's'){


        inputFromUser = 'r';

        while(inputFromUser == 'r') {

            launchGame();

            printf("press 'r' to reload the game, or any other key to exit.\n");

            scanf(" %c", &inputFromUser);
     }

    }
}

void launchGame(){

    char player1 = ' ';

    char player2 ;

    while(1) {

        // taking the first player preference.

        printf("Choose 'X' or 'O' for player1 \n");

        scanf(" %c", &player1);

        if (player1 == 'X' || player1 == 'x') {

            player1 = 'X';

            player2 = 'O';

            break;

        } else if(player1 == 'o' || player1 == 'O') {

            player1 = 'O';

            player2 = 'X';

            break;

        } else

            printf("Please enter a valid player\n");

    }

    printf("Player1 is '%c' and Player2 is '%c'\n",player1,player2);

    printf("GAME STARTED\n");

    char grid[6][6] = {"1|2|3", "_ _ _", "4|5|6", "_ _ _", "7|8|9"};

    printGrid(grid);

    int countplayer1 = 0;

    int countplayer2 = 0;

    while(1) {

        positionFlag = 1;

        if(countplayer1 == 5 && countplayer2 == 4){

          
  printf("GAME ENDED\n");

            printf("It is a draw!\n");

            break;
        }

        if((countplayer2 + 1) != countplayer1) {

            printf("type the movement number for player 1\n");

            char move1;

            scanf(" %c", &move1);

            updateGame(move1, player1, grid);

            if (positionFlag) {

                printf("Invalid place, please select an empty    place!\n");

                printGrid(grid);

                continue;
            }

            printGrid(grid);

            countplayer1++;

           bool checkGame_p1 =gameEnded(grid);

            if(checkGame_p1){

             
   printf("GAME ENDED\n");

                printf("Player1 won!\n");
                break;}

        }
        positionFlag = 1;

        printf("type the movement number for player 2\n");

        char move2;

        scanf(" %c", &move2);

        updateGame(move2, player2, grid);
        if (positionFlag) {

            printf("Invalid place, please select an empty place!\n");

            printGrid(grid);

            continue;
        }

        printGrid(grid);

        countplayer2++;

        bool checkGame =gameEnded(grid);

        if(checkGame){

            printf("Player2 won!\n");

          
  printf("GAME ENDED\n");

            
break;}


    }
}

void printGrid(char grid [6][6]){

	int row;

    for( row = 0; row<5; row++) {

        printf("%s\n", grid[row]);
    }
}

void updateGame(char move,char player, char g [6][6]){

	int j;

    for(j= 0;j<6;j++){

    	int i;

        for( i = 0;i<6;i++){

            if (move == g[i][j] && (g[i][j] != 'X' ||g[i][j] != 'O') ){

                g[i][j] = player;

                positionFlag = 0;
            }
        }
    }
}


bool gameEnded(char grid[6][6]){
    bool winFlag = 0;

    int i;

        for(i = 0;  i<6; i = i+2)

            if(
           (grid[i][0] == grid[i][2] && grid[i][0] ==grid[i][4]) || 

                            (grid[0][i] == grid[2][i] && grid[0][i] == grid[4][i])||

                    (grid[0][0] == grid[2][2] && grid[0][0] == grid[4][4]) ||

                    (grid[0][4] == grid[2][2] && grid[0][4] == grid[4][0])

            )    winFlag =1;

    return winFlag;

}
