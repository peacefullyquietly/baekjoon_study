#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
using namespace std;

int get_many(vector<int> sorted_v, multiset<int> &s)
{

    sorted_v.erase(unique(sorted_v.begin(),sorted_v.end()),sorted_v.end());
    int flag, max = 0, result;
    for (int i = 0; i < sorted_v.size(); i++)
    {
        int count = s.count(sorted_v[i]);
        if (count > max)
        {
            max = count;
            flag = i;
            result = sorted_v[i];
        }
    }

    for (int i = flag+1; i < sorted_v.size(); i++)
    {
        int count = s.count(sorted_v[i]);
        if (count == max)
        {
            result = sorted_v[i];
            break;
        }
    }
    return result;
}

int main()
{
    vector<int> v;
    multiset<int> s;
    double av;
    int tc, n, mid, range, sum = 0;
    cin >> tc;
    v.reserve(tc);
    for(int i = 1; i <= tc; i++)
    {
        cin >> n;
        sum += n;
        v.push_back(n);
        s.insert(n);
    }
    sort(v.begin(),v.end());
    mid = v[(tc-1)/2];
    av = round(double(sum)/double(v.size()));
    int many = get_many(v,s);
    range = v.back()-v.front();
    if(av == -0) av = 0;

    cout << av;
    cout << '\n';
    cout << mid;
    cout << '\n';
    cout << many;
    cout << '\n';
    cout << range;
    cout << '\n';
}