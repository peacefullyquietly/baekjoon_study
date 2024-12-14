// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if (a < 0){
        cout << (b < 0 ? 3 : 2);
    }else{
        cout << (b < 0 ? 4 : 1);
    }
}