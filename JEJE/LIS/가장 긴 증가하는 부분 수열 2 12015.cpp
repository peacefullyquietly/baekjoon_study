#include<iostream>
#include<vector>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    vector<int> a, hmm;
    cin >> n;
    while(cin>>n)a.push_back(n);
    for(int i = 0; i < a.size(); i++)
    {
        if(hmm.empty() || hmm.back() < a[i])hmm.push_back(a[i]);
        else
        {
            int idx = lower_bound(hmm.begin(), hmm.end(), a[i])-hmm.begin();
            hmm[idx] = a[i];
        }
    }
    cout << hmm.size() << '\n';
}