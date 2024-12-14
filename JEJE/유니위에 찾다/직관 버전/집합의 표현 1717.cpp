// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.

//시간 초과 코드

#include<iostream>
using namespace std;
int N, M, u[1000001];

int find(int n)
{
    if(u[n] == n)return n;
    else return find(u[n]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    u[a] = b;
}

int main()
{
    cout << "TLE" << endl;
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i = 0; i < 1000001; i++) u[i] = i;
    cin >> N >> M;
    while(M--)
    {
        int order, a, b;
        cin >> order;
        cin >> a >> b;
        if(order)
        {
            if(find(a) == find(b))cout << "YES";
            else cout << "NO";
            cout << '\n';
        }
        else merge(a,b);
    }
}