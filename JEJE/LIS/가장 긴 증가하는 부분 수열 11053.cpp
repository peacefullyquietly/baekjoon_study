#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    vector<int> hmm;
    int n, tc;
    cin >> tc;
    while(cin >> n) v.push_back(n);
    for(int i = 0; i < tc; i++)
    {
        if(hmm.empty() || v[i] > hmm.back())hmm.push_back(v[i]);
        else
        {
            int idx = lower_bound(hmm.begin(),hmm.end(), v[i]) - hmm.begin();
            hmm[idx] = v[i];
        }
    }
    cout << hmm.size() << '\n';
}