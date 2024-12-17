// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<queue>
#define MAX 1001
#define p pair<int, int>
using namespace std;

int N, M;
int cnt[MAX], ans[MAX];
queue<p> q;
vector<int> list[MAX];

void toplogical_sorting(){
    while(!q.empty()){
        int subj = q.front().first, semester = q.front().second;
        q.pop();
        ans[subj] = semester;
        for(auto& i : list[subj]){
            cnt[i]--;
            if(cnt[i] == 0) q.push({i, semester+1});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        list[a].push_back(b); //a를 이수한 뒤에 b를 들을 수 있다.
        cnt[b]++; //b의 선수과목이 하나 늘었다.
    }
    for(int i = 1; i <= N; i++){
        if(cnt[i] == 0) q.push({i, 1}); //선수과목이 없는 과목은 1학기에 들을 수 있다.
    }
    toplogical_sorting();
    for(int i = 1; i <= N; i++) cout << ans[i] << ' ';
    cout << '\n';
}