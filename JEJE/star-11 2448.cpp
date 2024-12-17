// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<memory.h>
#include<vector>
using namespace std;


int n;
char base[3][6] = {
        "  *  ",
        " * * ",
        "*****"
    };
char star[3500][6500];


void make_star(int row, int col, int size){
    if(size == 3){
        for(int i=0; i<3; i++){
            for(int j=0; j<5; j++){
                star[row+i][col+j] = base[i][j];
            }
        }
        return;
    }else{
        make_star(row, col+size/2, size/2);
        make_star(row+size/2, col, size/2);
        make_star(row+size/2, col+size, size/2);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    memset(star, ' ', sizeof(star));
    make_star(0, 0, n);
    for(int i=0; i<n; i++){
        for(int j=0; j<2*n; j++){
            cout << star[i][j];
        }
        cout << '\n';
    }
}