// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <iostream>
#include <vector>
using namespace std;
int m, n;
bool use[9];
vector<int>v;
void nm2(int start)
{
	if (v.size() == m)
	{
		vector<int>::iterator out;
		for (out = v.begin(); out != v.end(); out++)
		{
			cout << *out << " ";
		}
		cout << "\n";
	}
	for (int i = start; i <= n; i++)
	{
		if (!use[i]&&(v.empty() || i > v.back()))
		{
				v.push_back(i);
				use[i] = true;
				nm2(i);
				v.pop_back();
				use[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	nm2(1);
	return 0;
}