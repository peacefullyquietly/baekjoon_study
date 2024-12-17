// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
using namespace std;

typedef struct _Info{
    int a, b, c;
    int max, idx;
}Info;

vector<Info> v;

bool cmpa(Info A, Info B) {
    return A.max - A.a < B.max - B.a;
}

bool cmpb(Info A, Info B) {
    return A.max - A.b < B.max - B.b;
}

bool cmpc(Info A, Info B) {
    return A.max - A.c < B.max - B.c;
}


void solve(int tc){
    int n, ans = 0, sum = 0;
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++){
        v[i].idx = i;
        cin >> v[i].a >> v[i].b >> v[i].c;
        v[i].max = max(v[i].a, max(v[i].b, v[i].c));
        ans += v[i].max;
        sum += v[i].a + v[i].b + v[i].c;
    }
    if(n < 3){
        cout << "#" << tc << " " << -1 << '\n';
    } else{
        int temp[3][3], idx[3][3], Min = INT_MAX;
        
        sort(v.begin(), v.end(), cmpa);
        for (int i = 0; i < 3; i++) {
            temp[0][i] = v[i].max - v[i].a;
            idx[0][i] = v[i].idx;
        }

        sort(v.begin(), v.end(), cmpb);
        for (int i = 0; i < 3; i++) {
            temp[1][i] = v[i].max - v[i].b;
            idx[1][i] = v[i].idx;
        }

        sort(v.begin(), v.end(), cmpc);
        for (int i = 0; i < 3; i++) {
            temp[2][i] = v[i].max - v[i].c;
            idx[2][i] = v[i].idx;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (idx[0][i] == idx[1][j]){
                    continue;
                } else {
                    for (int k = 0; k < 3; k++) {
                        if (idx[0][i] != idx[2][k] && idx[1][j] != idx[2][k]){
                            Min = min(Min, temp[0][i] + temp[1][j] + temp[2][k]);
                        }
                    }
                }
            }
        }
        ans -= Min;
        cout << "#" << tc << " " << sum - ans << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++){
        solve(i);
    }
}