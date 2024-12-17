// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N, M, B, v[501][501];
    set<int> s;
    cin >> N >> M >> B;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
        {
            cin >> v[i][j];
            s.insert(v[i][j]);
        }
    }
    int answer_time = 500*500*256*2+256, answer_heigh = -1;
    for(int nh = *s.begin(); nh <= *--s.end(); nh++)
    {
        int add = 0, remove = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++)
            {
                int ah = v[i][j] - nh;
                if(ah < 0) add -= ah;
                else remove += ah;
            }
        }
        if(remove + B >= add)
        {
            int nt = remove*2+add;
            //cout << nt << "\n";
            if(nt <= answer_time)
            {
                //cout << nh << "\n";
                answer_time = nt;
                answer_heigh = nh;
            }
        } 
    }
    cout << answer_time << ' ' << answer_heigh << '\n';

}