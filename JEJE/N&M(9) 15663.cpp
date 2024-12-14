#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<int> input;
vector<int> output;
bool use[10001] = { false, };

void nm8()
{
    if (output.size() == M)
    {
        for (auto& i : output) cout << i << ' ';
        cout << '\n';
            return;
    }
    int tmp = 0;
    for (int i = 0; i < input.size(); i++)
    {
        int j = input[i];
        if (!use[i] && (tmp != j))
        {
            output.push_back(j);
            use[i] = true;
            tmp = j;
            nm8();
            output.pop_back();
            use[i] = false;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    while (N--)
    {
        int dum;
        cin >> dum;
        input.push_back(dum);
    }
    sort(input.begin(), input.end());
    nm8();
    return 0;
}