// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    if(n%400 == 0){
        cout << 1;
    } else if((n%100 != 0) && (n%4 == 0)){
        cout << 1;
    } else {
        cout << 0;
    }
}