#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

int main(){
		
		srand(time(NULL)); //seeds the random function to prevent functions
						   //from being the same

		char guessWords[][16] = {
				"helmet",
				"pizza",
				"kangaroo",
				"systems",
				"super",
				"danger"
		};
		
		// index for random word
		int randomIndex = rand() % 6;
		
		int amountLives = 5;
		int amountCorrect = 0;
		int amountOldCorrect = 0;
		int index = 0;
		int sameGuess = 0;
		int quit = 0;

		//length of a word in the array
		int wordLength = strlen(guessWords[randomIndex]);
		//                       0 1 2 3 4 5 6 7
		int letterGuessed[8] = { 0,0,0,0,0,0,0,0 };
	
		char guess[16];
		char letterEntered;
		
		printf("guessWords:%s \nrandomIndex:%d \nwordLength:%d\n\n",
						guessWords[randomIndex],
						randomIndex,
						wordLength);

		//game's function 
		while(amountCorrect < wordLength){
				
				printf("\n\nNew Turn...\nHangman Word:");

				for(index = 0; index<wordLength; index++ ){
						if(letterGuessed[index] == 1){
								printf("%c", guessWords[randomIndex][index]);
						}else{
								printf("-");
						}
				}
				
				printf("\n");

				printf("%d correct letters!\n", amountCorrect);
				printf("guess a letter:");
				fgets(guess, 16, stdin); //reads line and stores it in str

				if( strncmp(guess, "quit", 4) == 0 ){
						quit =1;
						break;
				}

				letterEntered = guess[0];
				sameGuess = 0;
				printf("You chose:%c\n", letterEntered);
				
				amountOldCorrect = amountCorrect;
				
				for(index =0; index<wordLength; index++){
						if(letterGuessed[index] == 1){
								if(guessWords[randomIndex][index]== letterEntered){
										sameGuess =1;
										break;
								}
								continue;
						}
						
						if(letterEntered == guessWords[randomIndex][index]){
								letterGuessed[index] = 1;
								amountCorrect++;
						}
				}

				if(amountOldCorrect == amountCorrect && sameGuess == 0){
						amountLives--;
						printf("-----ouch! wrong letter-----\n");
						
						if (amountLives == 0){
								break;
						}
				} else if(sameGuess ==1){
						printf(">>>>>already guessed!<<<<<\n");
				} else{
						printf("*****correct!!*****\n");
					}
	
		} //while loop ends here

		if(quit == 1){
				printf("\n***Aww Don't Quit :(");
		}else if(amountLives == 0){
				printf("\n[[YOU LOST]]\nThe word was: %s\n", guessWords[randomIndex]); 
		}else{
				printf("\n[[YOU WON]]\nWo000t!\n");
		}

		return 0;
}

