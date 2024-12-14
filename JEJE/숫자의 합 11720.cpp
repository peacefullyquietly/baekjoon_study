#include<iostream>
using namespace std;
int main()
{
    int tc, sum = 0;
    char n;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        sum += (int)n - '0';
    }
    cout << sum << '\n';
}