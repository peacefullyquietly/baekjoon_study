#include<iostream>
using namespace std;

bool check(int n)
{
    int a1, a2, a3;
    if(n < 100) return true;
    if(n == 1000) return false;
    
    a1 = n/100; n %= 100;
    a2 = n/10; n %= 10;
    a3 = n;
    
    if(a1 - a2 == a2 - a3)return true;
    else return false;   
}

int main()
{
    int n, answer = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        if(check(i)) answer += 1;
    }
    cout << answer << '\n';
    return 0;
}