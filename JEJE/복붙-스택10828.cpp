// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, c;
	string str;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> c;
			v.push_back(c);
		}
		else if (str == "pop")
		{
			if (v.size() != 0)
			{
				cout << v.back() << "\n";
				v.pop_back();
			}
			else
			{
				cout << "-1" << "\n";
			}
		}
		else if (str == "size")
		{
			cout << v.size() << "\n";
		}
		else if (str == "empty")
		{
			if (v.size() != 0)
			{
				cout << "0" << "\n";
			}
			else
			{
				cout << "1" << "\n";
			}
		}
		else if (str == "top")
		{
			if (v.size() != 0)
			{
				cout << v.back() << "\n";
			}
			else
			{
				cout << "-1" << "\n";
			}
		}
	}
	
}