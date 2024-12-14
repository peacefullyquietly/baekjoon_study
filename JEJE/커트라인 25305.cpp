#include<iostream>
#include<queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, k = -1;
    priority_queue<int> q;
    cin >> n >> n;
    k+=n;
    while(cin >> n) q.push(n);
    while(q.size() > 1 && k--)q.pop();
    cout << q.top() << '\n';
}