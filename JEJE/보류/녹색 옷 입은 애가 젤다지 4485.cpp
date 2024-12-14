#include<iostream>
#include<queue>
#include<cstring>
#define MAX 126
#define INF 9*125*125*10;
using namespace std;
typedef pair<int, pair<int,int>> p;

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};
int N, v[MAX][MAX], d[MAX][MAX], outcnt = 1;

void print(int n)
{
    cout << "Problem " << outcnt << ": ";
    cout << n << '\n';
    outcnt++;
}

void dada()
{
    priority_queue<p,vector<p>,greater<p>> pq;
    pq.push({v[1][1], {1, 1}});
    while(!pq.empty())
    {
        int w = pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
        pq.pop();
        if(w > d[y][x]) continue;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
            if(w+v[ny][nx] < d[ny][nx])
            {
                d[ny][nx] = w+v[ny][nx];
                pq.push({w+v[ny][nx], {nx, ny}});
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(true)
    {
        cin >> N;
        if(N == 0)break;
        for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++)
        {
            cin >> v[i][j];
            d[i][j] = INF;
        }
        dada();
        // for(auto &i : d)
        // {
        //     for(auto &j : i)
        //     {
        //         cout << j << ' ';
        //     }
        //     cout << '\n';
        // }
        print(d[N][N]);
    }
}