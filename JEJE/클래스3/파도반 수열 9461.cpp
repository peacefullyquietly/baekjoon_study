#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    unsigned long tc, n, flag = 1, v[101];
    for(unsigned long int i = 1; i <= 3; i++) v[i] = 1;
    for(unsigned long int i = 4; i <= 5; i++) v[i] = 2;
    for(unsigned long int i = 6; i <= 100; i++) v[i] = v[i-2]+v[i-3];
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        cout << v[n] << '\n';
    }
}