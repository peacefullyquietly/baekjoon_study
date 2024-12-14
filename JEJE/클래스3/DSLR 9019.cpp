#include<iostream>
#include<queue>
#include<cstring>
#include<string>
using namespace std;

int start, flag;

int D(int n){
    return (n*2)%10000;
}int S(int n){
    if(n == 0)return 9999;
    else return n-1;
}int L(int n){
    return 10*(n%1000)+n/1000;
}int R(int n){
    return 1000*(n%10)+(n/10);
}

string bfs()
{
    queue<pair<int, string>> q;
    int qs = 0;
    bool visited[10000];
    memset(visited, false, sizeof visited);
    string s = "";
    q.push({start, s});
    visited[start] = true;
    while(!q.empty())
    {
        int n = q.front().first;
        string s = q.front().second;
        q.pop();
        if(n == flag) {cout << qs << '\n'; return s;}
        int Dd = D(n), Ss = S(n), Ll = L(n), Rr = R(n);
        if(!visited[Dd]){
            q.push({Dd,s+'D'});
            visited[Dd] = true;
        }if(!visited[Ss]){
            q.push({Ss,s+'S'});
            visited[Ss] = true;
        }if(!visited[Ll]){
            q.push({Ll,s+'L'});
            visited[Ll] = true;
        }if(!visited[Rr]){
            q.push({Rr,s+'R'});
            visited[Rr] = true;
        }
        //qs += 1;
    }
    return "";
    }

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        cin >> start >> flag;
        cout << bfs() << '\n';
    }
}