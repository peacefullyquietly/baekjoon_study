// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
#define MAX 10001
using namespace std;

int n;
int A[MAX], B[MAX];

bool isSame(){
    return equal(A, A+n, B);
}

void sovle(){
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            if (A[j] > A[j+1]) {
                swap(A[j], A[j+1]);
                if (A[j+1] == B[j+1]) {
                    if (isSame()) {
                        cout << 1 << '\n';
                        return;
                    }
                }
            }
        }
    }
    cout << 0 << '\n';
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < n; i++){
        cin >> B[i];
    }

    if(isSame()){
        cout << 1 << '\n';
        return 0;
    }else{
        sovle();
    }
}