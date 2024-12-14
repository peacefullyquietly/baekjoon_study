// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	
	long int tc, answer = 0;
	cin >> tc;
	vector<vector<long int>>  v(tc+1, vector <long int>(1, 0));
	for (int i = 0; i < tc; i++)
	{
		int x, color;
		cin >> x >> color;
		v[color].push_back(x);
	}
	
	for (int i = 0; i<v.size(); i++)
	{
		if (v[i].size() > 2)
		{
			sort(v[i].begin(),v[i].end());
			answer += v[i][2] - v[i][1];
			for (int j = 2; j < v[i].size()-1; j++)
			{
				answer += min(v[i][j + 1] - v[i][j], v[i][j] - v[i][j - 1]);
			}
			answer += v[i][v[i].size() - 1] - v[i][v[i].size() - 2];
		}
		
	}
	cout << answer << "\n";

}