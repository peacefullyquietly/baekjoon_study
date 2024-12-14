// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
using namespace std;

int N, answer = 0;
vector<int> take;
vector<int> money;

void find(int day, int m)
{
    if(day == N) {answer = max(m, answer); return;}
    else if(day > N) return;// 에초에 N(+1)일을 초과하는 상담이면
    find(day+1, m); // 건너 뜀 = 돈 안받음
    find(day+take[day], m+money[day]); // 상담함 = 시긴걸림, 돈받음
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    take.resize(N); money.resize(N);
    for(int i=0; i < N; i++)
    {
        cin >> take[i] >> money[i];
    }
    find(0,0);
    cout << answer << '\n';
}