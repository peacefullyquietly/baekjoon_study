#include <iostream>
#include<vector>
#include<numeric>
#include<string>
using namespace std;

bool check(string str)
{
	vector<char> check;
	int len = int(str.length());

	for (int i = 0; i < len; i++)
	{
		char c = str[i];
		if (c == '(' || c == '[')
		{
			check.push_back(c);
		}
		else if (c == ']' && check.size() != 0 && '[' == check.back())
		{
			check.pop_back();
		}
		else if (c == ')' && check.size() != 0 && '(' == check.back())
		{
			check.pop_back();
		}
		else if (c == ')' || c == ']') return false;
	}
	return check.empty();
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	string g, i;
	while(1)
	{
		getline(cin,g);
		if (g.length() == 1 && g == ".") break;
		if (check(g))
		{
			cout << "yes" << "\n";
		}
		else cout << "no" << "\n";

	}
}