#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> p;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc, n;
    
    cin >> tc;
    vector<int> v(tc);
    for(auto &i : v) cin >> i;
    vector<int> cv(v);
    sort(cv.begin(),cv.end());
    cv.erase(unique(cv.begin(),cv.end()),cv.end());
    for(auto &i : v)
    {
        int idx = lower_bound(cv.begin(), cv.end(), i) - cv.begin();
        cout << idx << ' ';
    }
    cout<<'\n';
}