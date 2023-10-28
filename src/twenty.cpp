//============================================================================
// Name        : twenty.cpp
// Author      : Sire Jean Codebien
// Version     :
// Copyright   : none
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "twentyFunc.h"
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

void printNiv();
//void calcDifficulty(int score);
void addBlocks();
void shiftUp();
void isGameOver();
void checkVoisin();
void gravity();

int main() {
	srand (time(NULL));
	initNiv(h, w, &niv, initval);
	while(1){
		shiftUp();
		addBlocks();
		checkVoisin();
		gravity();
		isGameOver();
		printNiv();
		cout << "_______" << endl; // fin de tour
		cout << "score"<< score << endl; // fin de tour
		cin.get();
	}
	return 0; // jamais atteint
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


void isGameOver(){
	for (int j = 0; j < w; j++) {
		if (niv[0][j] > 0) {
			cout << "GAMEOVR" << endl;
			break;
		}
	}
}

void checkVoisin(){
	 for (int i = 0; i < h; i++) {
	        for (int j = 0; j < w; j++) {
	            // Comparer avec le voisin à droite (si ce n'est pas la dernière colonne)
	            if (j < w - 1 && niv[i][j] == niv[i][j+1] && niv[i][j]!=0 )  {
	            	niv[i][j] = 0;
	            	niv[i][j+1] = 0;
	                score++;
	                //cout << "voisins a (" << i << ", " << j << ") et (" << i << ", " << j + 1 << ")\n";
	            }
	            // Comparer avec le voisin en dessous (si ce n'est pas la dernière ligne)
	            if (i < h - 1 && niv[i][j] == niv[i + 1][j] && niv[i][j]!=0) {
	            	niv[i][j] = 0;
	            	niv[i + 1][j] = 0;
	            	score++;
	                //cout << "voisins a (" << i << ", " << j << ") et (" << i + 1 << ", " << j << ")\n";
	            }
	        }
	 }
}

void gravity(){
	for (int i = h-1; i > 0; i--) {
		        for (int j = w; j > 0; j--) {
		            // chercher un vide sous la case
		            if (niv[i+1][j] == 0) {
		            	niv[i+1][j] = niv[i][j];
		            	niv[i][j] = 0;
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
