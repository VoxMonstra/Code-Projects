/************************************************************
 *	File Name:  functions.cpp
 *	Author:  Noah Gregory
 *	Date Created:  10/23
 *	Purpose:  Game of Hangman
 ************************************************************/
	
#include <ctime>    
#include "hangman.h"

void printAsterisk(){
    for(int i = 0; i < 80; i++){
        cout << "*";
    }
    cout << endl << endl;
}

string getWord(){
	ifstream infile;
    int random;
    string word, trash;
    infile.open("wordBank.txt");
    if(!infile.is_open()){
        cout << endl << "Could not open file";
        return "fail";
    }

    srand(time(NULL));
    random = rand() % 10 + 1;

    for(int i = 0; i < random - 1; i++){
        infile >> trash;
    }
    infile >> word;

    infile.close();
	return word;
}

void printWord(char underScores[21], char word[21]){
    int length = 0;
    for(int i = 0; i < 20; i++){
        if(word[i] != ' '){
            length += 1;
        }else{
            i = 20;
        }
    }
    cout << "WORD: ";
    for(int i = 0; i < length; i++){
        cout << underScores[i] << " ";
    }
}

bool getContinue(){
    char choice;
    cout << endl << "Do you want to play hangman again? (y/n):" << endl;
    cin >> choice;
    while( !(choice == 'y'|| choice == 'n') ){
        cout << endl << "Invalid response, try again:" << endl;
        cin >> choice;
    }

    if(choice == 'y'){
        return true;
    }
    else{
        return false;
    }

}

void printLettersGuessed(bool userGuesses[26], char alphabet[27]){
    int count = 0;
    cout << endl << endl << endl;
    cout << "Letters you have already guessed: ";

    for(int i = 0; i < 26 ; i++){
        if(userGuesses[i] == true){
            cout << alphabet[i] << " ";
            count += 1;
        }
    }

    if(count == 0){
        cout << "(none have been guessed yet)";
    }

    cout << endl << endl;

    for(int i = 0; i < 80 ; i++){
        cout << "-";
    }

}

int guessLetter(bool userGuesses[26], char alphabet[27]){
    int letterIndex;
    char guess;
    cout << endl << "What letter do you guess?   ";
    cin >> guess;
    guess = toupper(guess);
    
    for(int i = 0; i < 26; i++){
        if(guess == alphabet[i]){
            letterIndex = i;
        }
    }

    if(userGuesses[letterIndex] == true){
        cout << "You already guessed that letter, try again: ";
        letterIndex = guessLetter(userGuesses, alphabet);
    }
    return letterIndex;
}

bool checkGuess(int index, char alphabet[27], char word[21]){
    int count = 0;
    char guess = alphabet[index];
    for(int i = 0; i < 20; i++){
        if(guess == word[i]){
            count++;
        }
    }
    if(count == 0){
        return false;
    }
    else{
        return true;
    }

}

void printScore(bool check){
    if(check == false){
        for(int i = 0; i < 33; i++){
            cout << "<";
        }

        cout << "  INCORRECT  ";

        for(int i = 0; i < 33; i++){
            cout << "<";
        }
    }

    if(check == true){
        for(int i = 0; i < 35; i++){
            cout << "<";
        }

        cout << "  CORRECT  ";

        for(int i = 0; i < 34; i++){
            cout << "<";
        }
    }
}

bool checkGameOver(char word[21], char underScores[21], int stage){
    int count = 0;
    if(stage == 6){
        return true;
    }
    else{
        for(int i = 0; i < 20; i++){
            if(word[i] != ' ' && word[i] != underScores[i]){
                count++;
            }
        }
    }

    if(count == 0){
        return true;
    }
    else{
        return false;
    }

}

void printStage(int stage){
    cout << endl;
	switch(stage)
	{	
		case 0:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;
		
		case 1:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 2:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |     |        \n";
					cout << "     |     |        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 3:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |     |\\      \n";
					cout << "     |     |        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 4:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |    /|\\      \n";
					cout << "     |     |        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 5:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |    /|\\      \n";
					cout << "     |     |        \n";
					cout << "     |      \\      \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 6:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |    /|\\      \n";
					cout << "     |     |        \n";
					cout << "     |    / \\      \n";
					cout << "     |              \n";
					cout << "     |   DEAD!      \n";
					cout << "  --------------    \n";
					break;	
	}
	cout << "\n\n";
}

void printResult(int stage, string answer){
    if(stage == 6){
        printStage(stage);
    }
    else{
        cout << endl << "Yes! the word was:  " << answer << endl;
        for(int i = 0; i < 35; i++){
            cout << "<";
        }

        cout << "YOU WIN!";

        for(int i = 0; i < 35; i++){
            cout << "<";
        }
    }
}