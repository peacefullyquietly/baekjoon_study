// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int M, N;
vector<int> input;
vector<int> out;
bool use[10001];


void nm5()
{
    if ((int)out.size() == M)
    {
        for (auto i : out) cout << i << ' ';
        cout << '\n';
        return;
    }
    for (auto j : input)
    {
        if (!use[j])
        {
            use[j] = true;
            out.push_back(j);
            nm5();
            use[j] = false;
            out.pop_back();
        }
    }
    return;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    while (N--)
    {
        int dum;
        cin >> dum;
        input.push_back(dum);
    }
    sort(input.begin(), input.end());
    nm5();
    return 0;
}
