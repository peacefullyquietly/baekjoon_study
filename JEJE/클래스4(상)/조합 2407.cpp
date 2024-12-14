#include<iostream>
#include<string>
#include <cmath>
using namespace std;
typedef __uint128_t l;


l c[101][101];

l comb(l n, l m)
{
    if(c[n][m] > 0) return c[n][m];
    if(m > n-m) return(comb(n, n-m));
    if(n == m || m == 0) return 1;
    c[n][m] = comb(n-1, m) + comb(n-1, m-1);
    return c[n][m];
}

string change(l result)
{
    string r = ""; 
    string f = to_string((long long) (result /  (__uint128_t) pow(10, 15))); 
    string s = to_string((long long) (result % (__uint128_t) pow(10, 15))); 
    if ( f == "0") return s;
    else return f + s; 
}   

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a, b;
    cin >> a >> b;
    for(int i = 0; i < 101; i++)
    {
        c[i][i] = 1;
        c[i][0] = 1;
    }
    l ans = comb(a, b);
    string s = change(ans);
    
    cout << s << '\n';
}