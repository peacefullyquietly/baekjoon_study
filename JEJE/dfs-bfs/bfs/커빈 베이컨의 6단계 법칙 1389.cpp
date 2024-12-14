#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int> p;

int U, R;
vector<int> list[101]; //인접 리스트
set<int> user; //유저 명단
bool visit[101]; //방문여부
int num[101]; //각 사람별 베이컨수
struct Bacon {
    int node, bacon;// sum;
};

void bfs(int node)
{
    queue<Bacon> q;
    //int last = 0;
    q.push({node, 0});
    while(!q.empty())
    {
        int node = q.front().node, bacon = q.front().bacon; // sum = q.front().sum;
        //last = sum+bacon;
        q.pop();
        if (num[node] == 0)num[node] = bacon;
        else num[node] = min(num[node], bacon);
        visit[node] = true;
        for(auto &i : list[node])
        {
            if(!visit[i])
            {
                q.push({ i, bacon + 1}); // bacon + sum});
            }
        }
    }
    //return last;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> U >> R;
    while(R--)
    {
        int a, b;
        cin >> a >> b;
        user.insert(a);
        user.insert(b);
        list[a].push_back(b);
        list[b].push_back(a);
    }
    p answer = {100000000,100000000};
    for(auto &i:user)
    {
        memset(visit, false, sizeof visit);
        memset(num, 0, sizeof num);
        bfs(i);
        int sum = 0;
        for (auto& j : num) sum += j;
        answer = min(answer, {sum, i});
    }

    cout << answer.second << '\n';
}