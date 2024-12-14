#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int xp[] = {-1, 1, -1, 1, 2, 2, -2, -2};
int yp[] = {2, 2, -2, -2, -1, 1, -1, 1};
int count[300][300];
int ex, ey;

struct Info{
    int x, y, cnt;
};

int bfs(int &sx, int &sy, queue<Info> &q, vector<vector<bool>> &board)
{
    q.push({sx, sy, 0});
    board[sx][sy] = true;
    while(!q.empty())
    {
        int x = q.front().x, y = q.front().y, cnt = q.front().cnt;
        q.pop();
        //cout << "===" << x << " " << y << "\n";
        if(x == ex && y == ey)
        {
            cout << cnt << '\n';
            return 0;
        }
        for(int i = 0; i < 8; i++)
        {
            int nx = x + xp[i];
            int ny = y + yp[i];
            if(nx < 0 || ny < 0 || nx >= board.size() || ny >= board.size()) continue;
            if(board[nx][ny])continue;
            q.push({nx, ny, cnt+1});
            board[nx][ny] = true;
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int sx, sy, size;
        cin >> size;
        vector<vector<bool>> board(size, vector<bool>(size, false));
        queue<Info> q;
        cin >> sx >> sy;
        cin >> ex >> ey;
        bfs(sx, sy, q, board);
    }    
}