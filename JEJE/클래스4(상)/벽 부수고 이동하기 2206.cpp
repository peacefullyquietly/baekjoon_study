// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
using namespace std;

int sx, sy, v[1001][1001];
bool use[1001][1001][2];

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

struct Info{
    int x, y, cnt;
    bool broken;
};queue<Info> q;

int bfs()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    q.push({0,0,1,false});
    use[0][0][0] = true;
    use[0][0][1] = true;
    while(!q.empty())
    {
        int x = q.front().x, y = q.front().y, cnt = q.front().cnt;
        bool broken = q.front().broken;
        q.pop();
        if(x == sx-1 && y == sy-1) return cnt;
        for(int i = 0; i < 4; i++)
        {
            int cx = x+dx[i];
            int cy = y+dy[i];
            if(cx < 0 || cx >= sx || cy < 0 || cy >= sy) continue;
            if(use[cy][cx][broken])continue;
            if(broken){
                if(v[cy][cx] == 1)continue;
                else {q.push({cx,cy,cnt+1,true});
                use[cy][cx][broken] = true;}
            }else{
                if(v[cy][cx] == 1)q.push({cx,cy,cnt+1,true});
                else q.push({cx,cy,cnt+1,false});
                use[cy][cx][broken] = true;
            }
        }
    }
    return -1;
}

int main()
{
    cin >> sy >> sx;
    char num;
    for(int i = 0; i < sy; i++){
        for(int j = 0; j < sx; j++){
            cin >> num;
            v[i][j] = num - '0';
        }
    }

    cout << bfs() << '\n';

}