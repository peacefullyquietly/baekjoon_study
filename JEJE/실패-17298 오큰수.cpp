// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <iostream>
#include<vector>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int>v;
	vector<int> ans;
	int n, k, biggest = 0;
	bool change = false;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		v.push_back(k);
	}
	for (int i = 0; i < n; i++)
	{
		vector<int>::iterator iter;
		iter = v.begin();
		iter += i;
		biggest = *iter;
		change = false;
		for (iter; iter != v.end(); iter++)
		{
			if (*iter > biggest)
			{
				biggest = *iter;
				change = true;
				break;
			}

		}
		if (change)
		{
			ans.push_back(biggest);
		}
		else ans.push_back(-1);
	}
	vector<int>::iterator priter;
	for (priter = ans.begin(); priter != ans.end(); priter++)
	{
		cout << *priter << "\n";
	}

}