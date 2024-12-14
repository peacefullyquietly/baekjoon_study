#include<iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b=0;
    int cnt = 5;
    while(cnt--)
    {
        cin >> a;
        b += a*a;
    }
    cout << b%10 <<'\n';
}