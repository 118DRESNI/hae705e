#include "twentyFunc.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;


void initNiv(const int h, const int w, int (*niv)[8][7], int initval){
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            *niv[i][j] = initval;
        }
    }
}

