/*
*   Title: hangman.cpp
*   Author: Noah Gregory
*   Date: 10/23
*   Purpose: To simulate a game of hangman
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "hangman.h"
using namespace std;

int main(){

    //Declaring variables
    char word[21];
    char underScores[21];
    char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    bool userGuesses[26];
    bool cont = false, check = false, gameOver = false;
    int i = 0, stage = 0, letterIndex = 0;
    string answer;

    do{
        answer = getWord();// gets the word to guess

        for(int i = 0; i < answer.size(); i++){
            word[i] = answer[i]; //puts the answer word inside of the word C-STRING
        }

        for(int i = answer.size() ; i < 21; i++){
            word[i] = ' '; // fills extra array indeces with spaces
        }

        if(answer == "fail"){
            cout << endl << "Closing program"; // will close the program if a word couldnt be retrieved
            return 1;
        }

        for(int i = 0; i < 26; i++){
            userGuesses[i] = false; // sets all userGuesses to false
        }

        for(int i = 0; i < 20 ; i++){
            underScores[i] = '_'; // sets underScores to underscores
        }

        gameOver = false;
        stage = 0;

        do{
            printAsterisk(); // prints line of asterisks

            printWord(underScores, word); // prints the updated underscores array

            printStage(stage); // prints the hangman diagram

            printLettersGuessed(userGuesses, alphabet); // prints guessed letters

            letterIndex = guessLetter(userGuesses, alphabet); // function to return the index of the letter guessed without guessing a letter that has already been guessed

            userGuesses[letterIndex] = true; // records which letter the user guessed

            check = checkGuess(letterIndex, alphabet, word); // checks if guess is correct or incorrect

            if(check == false){ // adds to stage if guess is wrong
                stage++;
            }

            printScore(check); // prints correct or incorrect

            if(check == true){ // updates the underScores array for the next iteration of the game
                for(int i = 0; i < 21; i++){
                    if(word[i] == alphabet[letterIndex]){
                        underScores[i] = alphabet[letterIndex];
                    }
                }
            }

            cout << endl << "Press ENTER to continue."; // waits for the enter key to be pressed
            cin.ignore();
            cin.ignore();

            gameOver = checkGameOver(word, underScores, stage); // checks if game is either won or lost

        }while(gameOver == false);

        printResult(stage, answer); // prints the win screen or lose screen

        cont = getContinue(); // asks if want to play again

    }while(cont == true); // repeats if user wants to play again

    return 0;
}
