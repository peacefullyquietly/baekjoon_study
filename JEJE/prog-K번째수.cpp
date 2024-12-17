// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
//https://programmers.co.kr/learn/courses/30/lessons/42748

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer, v;
    int i,j,k;
    for(auto& command : commands)
    {
        i = command[0]; j = command[1]; k = command[2];
        v.assign(&array.begin()+i-1, &array.begin()+j);
        sort(v.begin(), v.end());
        answer.push_back(v[k-1]);
    }
    return answer;
}