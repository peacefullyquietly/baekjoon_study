// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>

using namespace std;

int n, arr[1000001], ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    for(int i = 4; i <= n; i++)
    {
        arr[i] = arr[i-1];
        if(i%3 == 0){
            arr[i] = min(arr[i/3], arr[i]);
        }
        if(i%2 == 0){
            arr[i] = min(arr[i/2], arr[i]);
        }
        arr[i] += 1;
    }
    cout << arr[n] << '\n';
    // for(int i = 4; i <= n; i++) cout << arr[i] << ' ';
}