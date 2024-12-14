// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N;
bool use[10];
char a[20];
vector<string> answer;
string word;

bool check(int i, int max)
{
    int j = max - 1;
    if (a[j] == '<')
    {
        if ((int)word[j] > i) return false;
    }
    else if (a[j] == '>')
    {
        if ((int)word[j] < i) return false;
    }
    return true;
}

void view(int cnt)
{
    if (cnt == N + 1)
    {
        answer.push_back(word);
        return;
    }

    for (int i = 0; i <= 9; i++) 
    {
        char k = i + '0';
        if (!use[i] && (cnt == 0 || check(k, cnt)))
        {
            word.push_back(k);
            use[i] = true;
            view(cnt + 1);
            word.pop_back();
            use[i] = false;
        }
    }
    return;
}

int main()
{

    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    view(0);
    sort(answer.rbegin(), answer.rend());
    cout << answer.front() << '\n' << answer.back() << '\n';
}