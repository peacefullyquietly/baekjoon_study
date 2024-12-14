#include<iostream>
#include<queue>
using namespace std;

int udt[101];
int use[101];

struct Info{
    int num, cnt;
};

int bfs()
{
    queue<Info> q;
    q.push({1,0});
    use[1] = true;
    while(!q.empty())
    {
        int num = q.front().num, cnt = q.front().cnt;
        if(num == 100) return cnt;
        q.pop();
        for(int i = 1; i <= 6; i++)
        {
            if(use[num+i] || num+i > 100) continue;
            if(udt[num+i] > 0)q.push({udt[num+i], cnt+1});
            else q.push({num+i, cnt+1});
            use[q.back().num] = true;
        }
    }
}

int main()
{
    int tc, a, b;
    cin >> a >> b;
    tc = a+b;
    while(tc--)
    {
        cin >> a >> b;
        udt[a] = b;
    }
    cout << bfs() << '\n';
}