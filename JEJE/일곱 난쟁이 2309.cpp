#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
const int MAX = 9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int sum;
    vector<int> nan(MAX,0);
    for(int i = 0; i < MAX; i++)
    {
        cin >> nan[i];
    }
    sum = accumulate(nan.begin(), nan.end(), 0);
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
        {
            if(sum - nan[i] - nan[j] == 100 && i != j) 
            {
                // cout << nan[i] << ':' << nan[j] << '\n';
                nan[i] = nan[j] = 0;
                sort(nan.begin(), nan.end());
                for(auto i : nan)
                {
                    if(i != 0) cout << i << '\n';
                }
                return 0;           
            }
        }
    }
    return 0;

}