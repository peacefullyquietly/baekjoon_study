// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <iostream>
#include<vector>
#include<numeric>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	vector<int> v;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> m;
		if (m != 0)
		{
			v.push_back(m);
		}
		else
		{
			v.pop_back();
		}
	}
	cout << accumulate(v.begin(), v.end(), 0) << "\n";

}
