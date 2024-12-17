// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <iostream>
#include <vector>
using namespace std;
int n, cnt;
bool targeting;
vector<int>v(15);

int nqp(int y)
{
	
	if (y == n)++cnt;
	for (int x = 0; x < n; x++)
	{
		targeting = false;
		for (int j = 0; j < y; j++)
		{
			if (v[j]==x || abs(y - j) == abs(v[j] - x))
			{
				targeting = true;
				break;
			}
		}
		if (!targeting)
		{
			v[y] = x;
			nqp(y + 1);
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(); cout.tie();
	cin >> n;
	nqp(0);
	cout << cnt << "\n";
}