#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i *= 10)
    {
        ans += (n-i+1);
    }
    if(ans==0) ans = 1;
    cout << ans << '\n';

}