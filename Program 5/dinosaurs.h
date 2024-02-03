#ifndef DINOSUARS_H
#define DINOSAURS_H

#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <cctype>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Stats
{
    int hp;// health points
    int ap;// attack points
};

struct Dino
{
    string type;
    string name;
    Stats dinoStats;
};

void printArt();
int getValidateInput(int, int, string);
int preloadDinos(int, Dino*);
int displayMenu();
void enterDinos(int, int&, Dino*);
void printDinos(int, Dino*);
void fight(int&, Dino*);
void saveToFile(int, Dino*);
void deleteDino(int, int, Dino*);

#endif