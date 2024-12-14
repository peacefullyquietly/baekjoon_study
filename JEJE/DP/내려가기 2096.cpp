#include<iostream>
#include<cstring>
#define MAX 3
using namespace std;
int n, tc, dp_min[MAX], dp_max[MAX], S0, S2, input[MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> tc;
    for(int i = 1; i <= tc; i++)
    {
        for(int j = 0; j < 3; j++) cin >> input[j];
        S0 = dp_max[0]; S2 = dp_max[2];
        /*0번과 2번은 서로 영향을 주지 않으므로 먼저
        계산하고 1번은 0번과 2번의 영향을 받으므로
        따로 저장 */
        dp_max[0] = max(dp_max[0],dp_max[1])+input[0];
        dp_max[2] = max(dp_max[1],dp_max[2])+input[2];
        dp_max[1] = max(S0, max(S2, dp_max[1]))+input[1];

        S0 = dp_min[0]; S2 = dp_min[2];
        dp_min[0] = min(dp_min[0],dp_min[1])+input[0];
        dp_min[2] = min(dp_min[1],dp_min[2])+input[2];
        dp_min[1] = min(S0, min(S2, dp_min[1]))+input[1];
    }
    cout << max(dp_max[0],max(dp_max[1], dp_max[2])) << ' ';
    cout << min(dp_min[0],min(dp_min[1], dp_min[2])) << '\n';
}