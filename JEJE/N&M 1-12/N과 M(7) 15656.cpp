#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> in;
vector<int> out;

void nm7()
{
    if(out.size() == M)
    {
        for(auto i : out) cout << i << ' ';
        cout << '\n';
        return;
    }

    for(auto j : in)
    {
        out.push_back(j);
        nm7();
        out.pop_back();
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    while(N--)
    {
        int dum;
        cin >> dum;
        in.push_back(dum);    
    }
    sort(in.begin(), in.end());
    nm7();
    return 0;
    
}