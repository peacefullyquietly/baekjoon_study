#include<iostream>
#include<queue>
#include<set>
using namespace std;

// struct Compare{
//     bool Operater() (const int &a, const int &b, const int &c) const{

//     }
// }
struct Info{
    int a, b, cnt;
}; queue<Info> q;
set<pair<int,int>> s;
int bucket[2], target[2];

bool c(int a, int b)
{
    return a >= 0 && b >=0; 
}

int bfs()
{
    q.push({0, 0, 0});
    s.insert({0, 0});
    while(!q.empty())
    {
        int a = q.front().a, b = q.front().b, cnt = q.front().cnt;
        if(a == target[0] && b == target[1]) return cnt;
        q.pop();
        int na, nb;
        
        //F
        na = bucket[0];if(!s.count({na, b}) && c(na, b))
        {
            q.push({na, b, cnt+1}); s.insert({na, b});
        }
        nb = bucket[1];if(!s.count({a, nb}) && c(a, nb)) 
        {
            q.push({a, nb, cnt+1}); s.insert({a, nb});
        }
        
        //E
        if(!s.count({0, b}) && c(0, b)) 
        {
            q.push({0, b, cnt+1}); s.insert({0, b});
        }
        if(!s.count({a, 0}) && c(a, 0)) 
        {
            q.push({a, 0, cnt+1}); s.insert({a, 0});
        }
        
        //M
        int emptyA = bucket[0] - a;
        int emptyB = bucket[1] - b;
        
        if(emptyB > a && !s.count({0, a+b}) && c(0, a+b)) {
            q.push({0, a+b, cnt+1}); s.insert({0, a+b});
        } else if(!s.count({a-emptyB, bucket[1]}) && c(a-emptyB, bucket[1])) {
            q.push({a-emptyB, bucket[1], cnt+1}); s.insert({a-emptyB, bucket[1]});
        }
        
        if(emptyA > b && !s.count({a+b, 0}) && c(a+b, 0)) {
            q.push({a+b, 0, cnt+1}); s.insert({a+b, 0});
        } else if(!s.count({bucket[0], b - emptyA}) && c(bucket[0], b - emptyA)) {
            q.push({bucket[0], b - emptyA, cnt+1}); s.insert({bucket[0], b - emptyA});
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> bucket[0] >> bucket[1];
    cin >> target[0] >> target[1];
    cout << bfs() << '\n';
}