// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, s, v[50];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> s;

    for(int i = 0; i < n; i++){
        int max = v[i], max_idx = i;
        for(int j = i+1; j < n  && j <= i+s; j++){
            if(max < v[j]){
                max = v[j];
                max_idx = j;
            }                        
        }
        s -= (max_idx - i);
        while(max_idx > i){
            swap(v[max_idx], v[max_idx-1]);
            max_idx--;
        }
    }

    for(int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
}