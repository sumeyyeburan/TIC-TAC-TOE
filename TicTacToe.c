#include <stdio.h>
#include <stdlib.h> //for srand()
#include <time.h>   //for time(NULL)

char board [3][3];
const char PLAYER='X';
const char COMPUTER='O';

void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char winner);

int main(){
	char winner=' ';
	int i,j;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n****** WELCOME TIC TAC TOE GAME ******\n");
	for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
	
	while(winner==' ' && checkFreeSpaces()>0){
		printBoard();
		
		playerMove();
		winner=checkWinner();
		
		printBoard();
		computerMove();
		winner=checkWinner();	
 	}
	printBoard();
	printWinner(winner);
	
	printf("\nTHANKS FOR PLAYING...\n");
	
	return 0;
}

void printBoard(){
	printf("\n");
	printf("   %c | %c  | %c ",board[0][0],board[0][1],board[0][2]);
	printf("\n ----|----|----\n");
	printf("   %c | %c  | %c ",board[1][0],board[1][1],board[1][2]);
	printf("\n ----|----|----\n");
	printf("   %c | %c  | %c ",board[2][0],board[2][1],board[2][2]);
	printf("\n");
}

int checkFreeSpaces(){
	int freeSpaces=0;
	int i,j;
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j]==' '){
				freeSpaces++;
			}
		}
	}
	
	return freeSpaces;
}

void playerMove(){
	int row,column;
	
	if(checkFreeSpaces()>0){
		do{
			printf("\nPlease enter row between 1 to 3 : ");
			scanf("%d",&row);
			row--;  // between 0 to 2
			
			printf("Please enter column between 1 to 3 : ");
			scanf("%d",&column);
			column--;  // between 0 to 2
		
			if(row>=0 && row<3 && column>=0 && column<3){
				if(board[row][column]!=' '){
					printf("\nIvalid Input! This cell is already occupied.\n");
				}
				else{
					printf("\nX placed!\n");
					board[row][column]=PLAYER;
					break;
				}
			}
			else {
                printf("\nInvalid Input! Row and column must be between 1 and 3.\n");
            }
		}while(1);
	}
	else{
		printWinner(' ');
	}
}

void computerMove(){
	srand(time(NULL));
	int row,column;
	
	if(checkFreeSpaces()>0){
		
		do{
			row=rand()%3;
			column=rand()%3;
		}while(board[row][column]!=' ');
		
		printf("\nO placed!\n");
		board[row][column]=COMPUTER;
	}
	else{
		if(checkWinner()!=' '){
			return;
		}
		else{
			printWinner(' ');
		}
	}
}

char checkWinner(){
	int i;
	
	// for row
	for(i=0;i<3;i++){
		if(board[i][0]==board[i][1] && board[i][0]==board[i][2]){
			return board[i][0];
		}
	}
	
	// for column
	for(i=0;i<3;i++){
		if(board[0][i]==board[1][i] && board[0][i]==board[2][i]){
			return board[0][i];
		}
	}
	
	// for diogonals
	if(board[0][0]==board[1][1] && board[0][0]==board[2][2]){
			return board[0][0];
	}
	if(board[2][0]==board[1][1] && board[2][0]==board[0][2]){
			return board[2][0];
	}
	
	return ' '; // no winner yet 
}

void printWinner(char winner){
	
	if(winner==PLAYER){
		printf("\nCONGRATULATIONS,YOU WIN !\n");
	}
	else if(winner==COMPUTER){
		printf("\nYOU LOST !\n");
	}
	else{
		printf("\nIT'S A TIE !\n");
	}
}
