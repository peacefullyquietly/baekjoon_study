#include<iostream>
#include<string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string n;
    int cnt = 0;
    while(cin >> n) cnt += 1;
    cout << cnt << '\n';
}