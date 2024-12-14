#include<iostream>
#include<string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    while (cin >> n)
    {
        int num = 0;
        for (int i = 1; i <= n; i++)
        {
        num = num*10+1;
        num %= n;
        if (num == 0) {cout << i << "\n"; break;}
        }
    }
}