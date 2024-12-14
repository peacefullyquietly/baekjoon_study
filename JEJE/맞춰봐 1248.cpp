// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<string>

using namespace std;

int n, answer[10], v[10][10];
bool use = false;

bool check(int max)
{
    int sum = 0;
    for (int i = max; i >= 0; i--) {
        sum += answer[i];
        if (v[i][max] == 0) {
            if (sum != 0) return false;
        }
        else if (v[i][max] > 0) {
            if (sum <= 0) return false;
        }
        else if (v[i][max] < 0) {
            if (sum >= 0) return false;
        }
    }
    return true;
}

bool view(int index)
{
    if (index == n)
    {
        return true;
    }
    if (v[index][index] == 0)
    {
        answer[index] = 0;
        return (check(index) && view(index + 1));
    }
    else {
        for (int i = 0; i <= 10; i++)
        {
            answer[index] = i * v[index][index];
            if (check(index) && view(index + 1)) return true;
        }
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> n;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++)
        {
            if (s[cnt] == '0')
            {
                v[i][j] = 0;
            }
            else if (s[cnt] == '+') {
                v[i][j] = 1;
            }
            else {
                v[i][j] = -1;
            }
            cnt += 1;
        }
    }
    view(0);
    for (int i = 0; i < n; i++) cout << answer[i] << ' ';
    cout << '\n';
}
