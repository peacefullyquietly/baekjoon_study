#include<iostream>
using namespace std;

int sum[1025][1025];

void make_sum(int s)
{
    for(int i = 1; i <= s; i++){
        for(int j = 1; j <= s; j++){
            sum[i][j] += sum[i][j-1];
        }
    }
    for(int i = 1; i <= s; i++){
        for(int j = 1; j <= s; j++){
            sum[i][j] += sum[i-1][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int s, tc;
    cin >> s >> tc;
    for(int i = 1; i <= s; i++){
        for(int j = 1; j <= s; j++){
            cin >> sum[i][j];
        }
    }
    make_sum(s);
    while(tc--)
    {
        int answer = 0;
        int sx, sy, ex, ey;
        cin >> sy >> sx >> ey >> ex;
        answer += sum[ey][ex];
        answer -= sum[ey][sx-1]+sum[sy-1][ex]-sum[sy-1][sx-1];
        cout << answer << '\n';
    }
}