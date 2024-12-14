#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long l;

l a,b,c;

l solve(l a, l x)
{
    if(x==0)return 1;
    else if(x==1)return a;
    l split = solve(a, x/2);
    if(x%2 == 0)return (split*split)%c;
    else return (split*solve(a, x/2+1))%c;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b >> c;
    cout << solve(a,b)%c << '\n';
}