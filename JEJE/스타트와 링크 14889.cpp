// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
using namespace std;

int N, answer = 1000000000;
vector<vector<int>> v(20, vector<int>(20));
bool use[20];

void view(int cnt, int start)
{
    if (cnt == N / 2)
    {
        vector<int> start;
        vector<int> link;
        for (int i = 0; i < N; i++)
        {
            if (use[i]) start.push_back(i);
            else link.push_back(i);
        }
        int start_s = 0, link_s = 0;
        for (int i = 0; i < N/2; i++) { //전부 탐색할 필요는 없으므로
            for (int j = 0; j < N/2; j++)
            {
                start_s += v[start[i]][start[j]];
                link_s += v[link[i]][link[j]];
            }
        }
        answer = min(abs(start_s - link_s), answer);
        return;
    }
    for (int i = start; i < N; i++)
    {
        if (!use[i])
        {
            use[i] = true;
            view(cnt + 1, i);
            use[i] = false;
        }
    }
    return;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
        }
    }
    view(0, 0);
    cout << answer;
    return 0;
}
