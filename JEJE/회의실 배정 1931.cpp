#include<iostream>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
typedef pair<int, int> p;
vector<p> q;

bool cmp(p a, p b)
{
    if(a.second == b.second){
        return a.first < b.first;
    }else return a.second < b.second;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, cnt = 0;
    cin >> a;
    while(cin >> a >> b)q.push_back({a, b});
    sort(q.begin(), q.end(), cmp);
    int pin = q[0].first;
    for(auto &i : q)
    {
        if(i.first >= pin)
        {
            cnt += 1;
            pin = i.second;
        }
    }
    cout << cnt << '\n';
}