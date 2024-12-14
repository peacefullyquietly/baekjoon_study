// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <iostream>
#include <algorithm>
using namespace std;

#define BASE 131072
#define NEGINF -1000000000000

struct Result {
    long long s, l, r, m;
};

int N, M;
long long arr[BASE];
Result tree[2*BASE+1];

inline Result merge(Result a, Result b){
    return {
        a.s + b.s,
        max(a.l, a.s+b.l),
        max(a.r+b.s, b.r),
        max({ a.m, b.m, a.r+b.l })
    };
}

void init(int s, int e, int n){
    if(s == e){
        tree[n] = { arr[s], arr[s], arr[s], arr[s] };
        return;
    }
    
    int m = (s + e) / 2;
    init(s, m, 2*n);
    init(m+1, e, 2*n+1);
    
    tree[n] = merge(tree[2*n], tree[2*n+1]);
}

Result query(int x, int y, int s, int e, int n){
    if(y < s) return { 0, 0, NEGINF, NEGINF };
    if(e < x) return { 0, NEGINF, 0, NEGINF };
    if(x <= s && e <= y) return tree[n];
    
    int m = (s + e) / 2;
    return merge(query(x, y, s, m, 2*n), query(x, y, m+1, e, 2*n+1));
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> arr[i];
    }
    
    init(1, N, 1);
    
    cin >> M;
    while(M--){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        if(y1 < x2){
            Result lres = query(x1, y1, 1, N, 1);
            Result mres = query(y1+1, x2-1, 1, N, 1);
            Result rres = query(x2, y2, 1, N, 1);
            cout << lres.r + mres.s + rres.l << '\n';
        } else {
            Result lres = query(x1, x2-1, 1, N, 1);
            Result mres = query(x2, y1, 1, N, 1);
            Result rres = query(y1+1, y2, 1, N, 1);

            cout << max({ mres.m, lres.r + mres.l, mres.r + rres.l, lres.r + mres.s + rres.l }) << '\n';
        }
    }

    return 0;
}