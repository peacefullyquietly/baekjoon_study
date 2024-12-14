// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;

int sq = 1;
int N, Q;
long long cnt[MAX];
long long ans[MAX];
vector<int> arr;

typedef struct _Query {
    int s, e, idx;
    bool operator < (const _Query &o) const {
        if(s/sq != o.s/sq) return s < o.s;
        else return e < o.e;
    }
} Query;
vector<Query> order_arr;

inline void setSq(int n){
    double ret = n;
    for (int i = 0; i < 16; i++) {
        ret = ret - (ret * ret - n) / (ret * 2);
    }
    sq = (int)ret;
}

// inline void _plus(int s, int e){
//     for(int i = s; i <= e; i++){
//         if(!cnt[arr[i]]++) ans[arr[i]]++;
//     }
// }

// inline void _minus(int s, int e){
//     for(int i = s; i <= e; i++){
//         if(!--cnt[arr[i]]) ans[arr[i]]++;
//     }
// }

int main(){
    // ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    setSq(N);
    arr.resize(N);
    for(auto &i : arr){
        cin >> i;
    }
    // cout << "end1" << "\n";

    cin >> Q;
    order_arr.resize(Q);
    int _ = 0;
    for(auto &i : order_arr){
        cin >> i.s >> i.e;
        i.idx = _++;
    }    
    sort(order_arr.begin(), order_arr.end());
    // cout << "end" << "\n";

    // cout << order_arr[0].idx;

    Query &tmp = order_arr[0];
    for(int i = tmp.s; i < tmp.e; i++){
        if(!cnt[arr[i]]++) ans[tmp.idx]++;
    }
    int left = 0;
    int right = 0;

    // Query &tmp = order_arr[0];
    // while(right < tmp.e) {
    //     right++;
    //     if(!cnt[arr[right]]++){
    //         ans[tmp.idx]++;
    //     }
    // }

    
    for(int j = 1; j < Q; j++){
        Query &i = order_arr[j];

        while(i.s < left) {
            left--;
            if(!cnt[arr[left]]++){
                ans[i.idx]++;
            }
        }
        while(right < i.e) {
            right++;
            if(!cnt[arr[right]]++){
                ans[i.idx]++;
            }
        }
        while(left < i.s) {
            if(!(--cnt[arr[left]])){
                ans[i.idx]--;
            }
            left++;
        }
        while(i.e < right) {
            if(!(--cnt[arr[right]])){
                ans[i.idx]--;
            }
            right--;
        }
    }

    for(int i = 0; i < Q; i++){
        cout << ans[i] << '\n';
    }
}