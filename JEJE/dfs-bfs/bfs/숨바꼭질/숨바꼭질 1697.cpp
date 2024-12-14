// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
using namespace std;
const int MAX = 100000;


struct Info{
    int pos, cnt;
}; queue<Info> q;
bool visit[MAX*2+1];
int su, bro;

int bfs()
{
    int last = 0;
    while(!q.empty())
    {
        int pos = q.front().pos, cnt = q.front().cnt;
        last = cnt;
        visit[pos] = true;
        q.pop();

        if(pos == bro) return last;
        if(pos-1 >= 0 && pos-1 < MAX*2 && !visit[pos-1]) q.push({pos-1,cnt+1});
        if(pos+1 >= 0 && pos+1 < MAX*2 && !visit[pos+1]) q.push({pos+1,cnt+1});
        if(pos*2 >= 0 && pos*2 < MAX*2 && !visit[pos*2]) q.push({pos*2,cnt+1});
    }
    return last;
}


int main()
{
    cin >> su >> bro;
    q.push({su, 0});
    cout << bfs() << '\n';
}

//엘콘도로 파사