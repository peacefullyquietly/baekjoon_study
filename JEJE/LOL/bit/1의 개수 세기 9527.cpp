#include<iostream>
#define ll long long
using namespace std;

ll one_count(ll n)
{
    ll ans = 0, a = n, b = 1;
    while (a)
    {
        ans += (n + 1) / (b << 1) * b; //a가 2의 제곱구간의 범위에서의 갯수
        if (a & 1)ans += (n + 1) % b; //a가 완전히 제곱수가 아니고 마지막 부호가 1이라면 
        a >>= 1; // 2로 나누기 (양수)
        b <<= 1; // 2의 제곱씩 늘리기
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll a, b;
    cin >> a >> b;
    cout << one_count(b) - one_count(a - 1) << '\n';
}