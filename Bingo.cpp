#include "Bingo.h"
#include <iostream>
using namespace std;

void Bingo :: Render()
{
    int number = 0;
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            box[j][i] = number;
            number++;
        }
    }
    srand(time(NULL));
    for(int i=0; i<777; i++) {
        ran1 = rand() % 5;
        ran2 = rand() % 5;
        ran3 = rand() % 5;
        ran4 = rand() % 5;
        
        temp = box[ran1][ran2];
        box[ran1][ran2] = box[ran3][ran4];
        box[ran3][ran4] = temp;
    }
}

void Bingo :: Print() 
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++) 
        {
            if(box[j][i]==32) 
            {
                cout << "# " << "\t";
            }
            else
            {
                cout << box[j][i] << "\t";
            }
        }
        cout << endl;
        cout << endl;
    }
}

void Bingo :: Update(int number)
{
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(box[j][i] == number) {
                box[j][i] == 32;
            }
        }
    }
}

int Bingo :: Check()
{
    int bin = 0;
    if(box[0][0]==32 && box[1][1] == 32 && box[2][2] == 32 && box[3][3] == 32 && box[4][4] == 32) {
        bin++;
    }
    if(box[4][0]==32 && box[3][1] == 32 && box[2][2] == 32 && box[1][3] == 32 && box[0][4] == 32) {
        bin++;
    }
    for(int i=0; i<5; i++) {
        int five = 0;
        for(int j=0; j<5; j++) {
            if(box[j][i] == 32) five++;
            if(five == 5) bin++;
        }
    }
    for(int i=0; i<5; i++) {
        int five=0;
        for(int j=0; j<5; j++) {
            if(box[i][j] == 32) five++;
            if(five==5) bin++;
        }
    }

    return bin;
}