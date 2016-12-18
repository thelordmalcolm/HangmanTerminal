#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int main(){
		
		srand(time(NULL)); //seeds the random function to prevent functions
						   //from being the same

		char guessWords[][16] = {
				"green",
				"yellow",
				"purple",
				"windows",
				"linux",
				"apple"
		};
		
		// index for random word
		int randomIndex = rand() % 6;
		
		int amountLives = 5;
		int amountCorrect = 0;
		int amountOldCorrect = 0;
		
		//length of a word in the array
		int wordLength = strlen(guessWords[randomIndex]);
		int letterGuessed[8] = { 0,0,0,0,0,0,0,0 };

		int quit = 0;

		char guess[16];

		while(amountCorrect < wordLength){
			
				printf("Which letter will you guess?:");
				fgets(guess, 16, stdin);

				if( strncmp(guess, "quit", 4) == 0 ){
						quit =1;
						break;
				}

		}

		if(quit == 1){
				printf("\nthe player quit!");
		}


		return 0;
}

