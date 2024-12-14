#include<iostream>
using namespace std;
int Ualgo(int n1, int n2)
{
    if(n2 == 0) return n1;
    else return Ualgo(n2, n1%n2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int a, b, gcd;
    cin >> a >> b;
    gcd = Ualgo(a,b);
    b = (a*b)/gcd;
    cout << gcd << '\n' << b << '\n';
    return 0;
}