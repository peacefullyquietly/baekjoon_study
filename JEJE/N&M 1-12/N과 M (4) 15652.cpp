// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> v;

int nm4()
{
	if (v.size() == m)
	{
		vector<int>::iterator out;
		for (out = v.begin(); out != v.end(); out++)
		{
			cout << *out << " ";
		}
		cout << "\n";
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		if (v.empty() || v.back() <= i)
		{
			v.push_back(i);
			nm4();
			v.pop_back();
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	nm4();
	return 0;
}