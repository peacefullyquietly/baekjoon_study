#include<iostream>
#include<vector>
using namespace std;

vector<int> v;

long long int cut(int h)
{
    long long int sum = 0;
    for (auto& i : v) if(i-h > 0)sum += i-h;
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc, flag, answer = 0;
    int up = 0, down = 0, mid = 0;
    cin >> tc >> flag;
    v.resize(tc);
    for (auto& i : v)
    {
        cin >> i;
        up = max(up, i);
    } 
    while (down <= up){
        int mid = (down + up) / 2;
        if (flag <= cut(mid)) { 
            down = mid + 1;
            answer = max(mid, answer);
        }else{
            up = mid - 1;
        }
    }

    cout << answer << '\n';
}