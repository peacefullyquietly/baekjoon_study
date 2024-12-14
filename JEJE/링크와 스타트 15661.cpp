#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, answer = 1000000000, v[20][20];
bool use[20];

void view(int cnt, int idx, int target)
{
    vector<int> start, link;
    int start_s = 0, link_s = 0;

    if (cnt == target)
    {
        for (int i = 0; i < N; i++)
        {
            if (!use[i]) start.push_back(i);
            else link.push_back(i);
        }

        for (int i = 0; i < start.size(); i++) {
            for (int j = 0; j < start.size(); j++)
            {
                start_s += v[start[i]][start[j]];
            }
        }

        for (int i = 0; i < link.size(); i++) {
            for (int j = 0; j < link.size(); j++)
            {
                link_s += v[link[i]][link[j]];
            }
        }
        answer = min(abs(start_s - link_s), answer);
        return;
    }


    for (int i = idx; i < N; i++)
    {
        if (!use[i])
        {
            use[i] = true;
            view(cnt + 1, i, target);
            use[i] = false;
        }
    }

}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 2; i <= N - 1; i++)
    {
        view(0, 0, i);
    }

    cout << answer;

    return 0;
}