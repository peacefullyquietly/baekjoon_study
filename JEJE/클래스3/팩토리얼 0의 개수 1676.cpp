#include<iostream>
using namespace std;

int main()
{
    int n, cnt = 0;
    cin >> n;
    for(int i = 2; i <= n; i++){
        for(int j = 5; j < 5*5*5*5; j *= 5){
            if(i%j == 0) cnt += 1;
        }
    } cout << cnt << '\n';
}