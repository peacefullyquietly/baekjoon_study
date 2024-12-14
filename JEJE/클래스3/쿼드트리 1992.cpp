#include<iostream>
#include<queue>
using namespace std;
typedef pair<int,int> p;
int main()
{
    priority_queue<int> q;
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        q.push(n);
    }
    cout << q.top();
    q.pop();
    cout << q.top();
}