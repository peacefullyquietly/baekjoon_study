// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
#define p pair<int, int>
#define MAX 1000000
using namespace std;

int N, K;
priority_queue<int> pq[12];
int player[12];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        pq[a].push(b);
    }
    while(K--){
        int mont[] = {3, 8, 3};
        for(auto& flag : mont){
            if(flag == 3){
                for(int i = 1; i <= 11; i++){
                    pq[i].push(player[i]);
                    player[i] = pq[i].top();
                    pq[i].pop();
                }
            }else if(flag == 8){
                for(auto& i : player){
                    if(i != 0){
                        i--;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(auto& i : player){
        ans += i;
    }
    cout << ans;
}