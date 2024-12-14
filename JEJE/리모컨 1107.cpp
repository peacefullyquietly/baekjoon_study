#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<bool> broken(10);
bool check_not_broken(string str)
{
    for (auto word : str)
    {
        int num = word - '0';
        if (broken[num]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int broken_C, answer, cnt, target;
    cin >> target;
    cin >> broken_C;

    for (int i = 0; i < broken_C; i++) {
        int j;
        cin >> j;
        broken[j] = true;
    }
    answer = abs(100 - target);
    for (int i = 0; i <= 1000000; i++)
    {
        string str = to_string(i);
        if (check_not_broken(str))
        {
            int nano_move = target - i;
            cnt = (str.size() + abs(nano_move));
            answer = min(answer, cnt);
        }

    }
    cout << answer << '\n';
    return 0;
}