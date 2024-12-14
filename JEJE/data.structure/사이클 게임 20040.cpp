// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
#define MAX 5000001
using namespace std;
int m, n, u[MAX];

int find(int n)
{
    if(u[n] == n) return n;
    else return u[n] = find(u[n]);
}

bool merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b) return true;
    else u[a] = b;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int ans = 0;
    cin >> n >> m;
    for(int i = 0; i <= n; i++)u[i] = i;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        if(merge(a, b))
        {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
}