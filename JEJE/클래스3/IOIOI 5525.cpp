#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int N, tc, cnt = 0, answer = 0;
    string s;
    cin >> N >> tc;
    cin >> s;
    for(int i = 2; i < s.size();)
    {
        if(s[i] == 'I'&&s[i-1] == 'O'&&s[i-2] == 'I')
        {
            cnt += 1;
            if(cnt == N)
            {
                cnt -= 1;
                answer+=1;
            }
            i += 2;
        }
        else
        {
            i += 1;
            cnt = 0;
        }
    }
    cout << answer << '\n';
}