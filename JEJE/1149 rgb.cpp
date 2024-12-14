#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> dp(1001);
    vector<vector<int>> house(1001, vector<int>(0,3));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (auto &j : house[i])
        {
            int a;
            cin >> a;
            j = a;
        }

    }
    dp[0] = *min_element(house[0].begin(), house[0].end());
    for(auto& i : house){
        for(auto& j : i)
        {
                       
        }
    }
    

}