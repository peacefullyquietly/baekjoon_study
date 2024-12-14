#include<iostream>
using namespace std;

int main()
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    cout << min(min(x,abs(x-w)),min(y,abs(y-h))) << '\n';
}