#ifndef _HANGMAN_H
#define _HANGMAN_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;


void printStage(int);
void printWord(char[], char[]);
string getWord();
void printAsterisk();
bool getContinue();
void printLettersGuessed(bool[], char[]);
int guessLetter(bool[], char[]);
bool checkGuess(int, char[], char[]);
void printScore(bool);
bool checkGameOver(char[], char[], int);
void printResult(int, string);

#endif