#include<iostream>
#include<queue>
using namespace std;
const int MAX = 100001, INF = 2000000000;
typedef pair<int,int> p;
bool visited[3*MAX];
int S, B, t[3*MAX];
priority_queue<p,vector<p>,greater<p>> pq;

int bfs()
{
    //first = distance, second = time
    pq.push({0,S});
    visited[S] = true;
    int end = INF;
    while(!pq.empty())
    //for(int i = 0; i < 100; i++)
    {
        int now = pq.top().second, time = pq.top().first;
        if(now == B) return time;
        //cout << now << endl;
        pq.pop();
        if(!visited[now*2] && now*2 >= 0 && now*2 < MAX+20){
            pq.push({time, now*2});
            t[now*2] = time;
            visited[now*2] = true;
        }if((!visited[now-1] || time+1 < t[now-1])&& now-1 >= 0 && now-1 < MAX+20){
            //cout << "work";
            pq.push({time+1, now-1});
            t[now-1] = time+1;
            visited[now-1] = true;
        }if((!visited[now+1] || time+1 < t[now+1])&& now+1 >= 0 && now+1 < MAX+20){
            //cout << "work";
            pq.push({time+1, now+1});
            t[now+1] = time+1;
            visited[now+1] = true;
        }

    }
    //cout << pq.size();
    return end;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> S >> B;
    cout << bfs() << '\n';
}