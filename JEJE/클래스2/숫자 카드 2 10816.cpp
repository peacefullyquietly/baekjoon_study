#include<iostream>
#include<map>
using namespace std;
typedef long long l;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    map<l,l> m;
    l tc, n;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        m[n] += 1;
    }
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        cout << m[n] << ' ';
    }
    cout << '\n'; 
}