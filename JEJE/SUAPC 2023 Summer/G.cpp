#include<bits/stdc++.h>
#define p pair<int, int>
using namespace std;

int N;
int solve_cnt[6];
vector<int> v[6];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N;

    for(int i = 1; i <= 5; i++){
        cin >> solve_cnt[i];
    }

    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    int ans = 0;
    for(int i = 1; i <= 5; i++){
        sort(v[i].begin(), v[i].end());
        for(int j = 1; j < solve_cnt[i]; j++){
            ans += v[i][j];
        }
        ans += 60 + v[i][solve_cnt[i]-1];
    }
    cout << ans-60;
}