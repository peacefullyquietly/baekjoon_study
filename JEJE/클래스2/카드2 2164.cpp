#include<iostream>
#include<queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    queue<int> q;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)q.push(i);
    while(1 != q.size())
    {
        q.pop();

        n = q.front();
        q.pop();
        q.push(n);
    }
    cout << q.front() << '\n';
}