//============================================================================
// Name        : twenty.cpp
// Author      : Sire Jean Codebien
// Version     :
// Copyright   : none
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

const int h = 8;const int w = 7;
int niv[h][w];
int initval = -1;
int score = 0;
int scoreprev = score;
int difficulty = 0;

void initNiv();
void printNiv();
//void calcDifficulty(int score);
void addBlocks(int difficulty);


int main() {
	initNiv();
	while(){
		printNiv();
		cout << "_______" << endl; // fin de tour
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
/*
void calcDifficulty(int score){
	if (score % 10 == 0 && score > scoreprev){
		difficulty++;
	}
}
*/
