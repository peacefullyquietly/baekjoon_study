// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
using namespace std;

int N, ans = 0;
int arr[51];

inline double get_slope(int x1, int y1, int x2, int y2){
    return (double)(y2 - y1) / (x2 - x1);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> N;
    for(int i = 1; i < N+1; i++) cin >> arr[i];

    for(int x1 = 1; x1 < N+1; x1++){
        int y1 = arr[x1], cnt = 0;
        double tmp = -2000000000;
        for(int x2 = x1-1; x2 > 0; x2--){
            if(tmp < get_slope(x1, y1, x2, arr[x2])){
                tmp = get_slope(x1, y1, x2, arr[x2]);
                cnt++;
            }
        }

        tmp = 2000000000;
        for(int x2 = x1+1; x2 <= N; x2++){
            if(tmp > get_slope(x1, y1, x2, arr[x2])){
                tmp = get_slope(x1, y1, x2, arr[x2]);
                cnt++;
            }
        }

        ans = max(cnt, ans);

    }

    cout << ans;
}