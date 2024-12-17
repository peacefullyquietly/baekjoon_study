// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};
int scale, flag, fx, fy, map[1000][1000];

struct Info
{
    int x, y, cnt;
};


void snail()
{
    Info num = {0, 0, scale*scale};
    while (true)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < scale-1; j++)
            {
                int x = num.x, y = num.y, cnt = num.cnt;
                map[y][x] = cnt;
                
                if(cnt == flag){
                    fx = x;
                    fy = y;
                }
                
                if (num.cnt == 1){
                    return;
                }

                int cx = x+dx[i];
                int cy = y+dy[i];
                if(map[cy][cx] == 0) num = {cx, cy, cnt-1};
                else break;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
    cin >> scale >> flag;
    snail();
    for(int i = 0; i < scale; i++){
        for(int j = 0; j < scale; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << fy+1 << " " << fx+1;
}