#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    long long num = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        num += (n/i)*i;
    }
    cout << num << "\n";
}