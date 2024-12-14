#include<iostream>
using namespace std;

bool check_p(int n)
{
    if (n==1) return false;
    for (int i = 2; i*i <= n; i++)
    {
        if(n%i==0)return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc, n, cnt = 0;
    cin >> tc;
    for(; tc > 0; tc--)
    {
        cin >> n;
        if(check_p(n)) cnt += 1;
    }
    cout << cnt << '\n';
}