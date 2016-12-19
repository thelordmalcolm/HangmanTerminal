#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

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
		
		char username[10];

		// index for random word
		int randomIndex = rand() % 6;
		
		int amountLives = 5;
		int amountCorrect = 0;
		int amountOldCorrect = 0;
		
		//length of a word in the array
		int wordLength = strlen(guessWords[randomIndex]);
		//                       0 1 2 3 4 5 6 7
		//  set value to 1
		//  if the letter
		//  is guessed
		int letterGuessed[8] = { 0,0,0,0,0,0,0,0 };

		int quit = 0;

		char guess[16];
		char letterEntered;
		
		printf("guessWords:%s \nrandomIndex:%d \nwordLength:%d\n\n",
						guessWords[randomIndex],
						randomIndex,
						wordLength);

		//game's function 
		while(amountCorrect < wordLength){
			
				printf("Which letter will you guess?:");
				fgets(guess, 16, stdin); //reads line and stores it in str

				if( strncmp(guess, "quit", 4) == 0 ){
						quit =1;
						break;
				}

				letterEntered = guess[0];
				printf("You chose:%c\n", letterEntered);

				for(int i=0; i<wordLength; i++ ){
						if(letterGuessed[i] == 1){
								continue;
						}
						
						if( letterEntered == guessWords[randomIndex][i] ){
								letterGuessed[i] = 1;
								amountCorrect++;
						}
				}
		}

		if(quit == 1){
				printf("\nthe player quit!");
		}


		return 0;
}

