// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;

int main()
{
    int n, cnt = 0;
    cin >> n;
    for(int i = 2; i <= n; i++){
        for(int j = 5; j < 5*5*5*5; j *= 5){
            if(i%j == 0) cnt += 1;
        }
    } cout << cnt << '\n';
}