#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(90 <= n)cout << 'A';
    else if(80 <= n) cout<<'B';
    else if(70 <= n) cout<<'C';
    else if(60 <= n) cout<<'D';
    else cout << 'F';
    cout << '\n';
}