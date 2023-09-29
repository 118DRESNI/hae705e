//============================================================================
// Name        : twenty.cpp
// Author      : Sire Jean Codebien
// Version     :
// Copyright   : none
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

const int h = 8;const int w = 7;
int niv[h][w];
int initval = 0;
int score = 0;
int scoreprev = score;
int difficulty = 5;

void initNiv();
void printNiv();
//void calcDifficulty(int score);
void addBlocks();
void shiftUp();

int main() {
	srand (time(NULL));
	initNiv();
	while(1){
		shiftUp();
		addBlocks();
		printNiv();
		cout << "_______" << endl; // fin de tour
		cin.get();
	}
	return 0; // jamais atteint
}

void initNiv(){
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            niv[i][j] = initval;
        }
    }
}

void printNiv(){
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
        	cout << niv[i][j];
        }
        cout << endl;
    }
}

void addBlocks(){
	for (int i=0; i <w; i++){
		niv[h-1][i] = rand() % (difficulty + 1);
	}
}

void shiftUp(){
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i > 0) {
                niv[i - 1][j] = niv[i][j];
            }
        }
    }
}

/*
void calcDifficulty(int score){
	if (score % 10 == 0 && score > scoreprev){
		difficulty++;
	}
}
*/
