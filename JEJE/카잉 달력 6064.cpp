#include<iostream>
#include<vector>
using namespace std;

int work()
{
    int M, N, x, y;
    cin >> M >> N >> x >> y;
    x-=1; y-=1;//0부터 시작하여 나머지를 이용한 연산이 가능하도록 만듬
    for(int i = x; i <(N*M); i+=M)//x자리를 바꾸면서
    {
        if(i%N == y)//y자리를 확인해봄
        {
            cout << i+1 << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--)
    {
        work();
    }
}