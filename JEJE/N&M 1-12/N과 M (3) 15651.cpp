#include <iostream>
#include <vector>
using namespace std;
int n, m;
bool use[9];
vector<int> v;

void nm3()
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

	for (int i = 1; i <= n; i++)
	{
		if (v.size() != m)//void
		{
			v.push_back(i);
			nm3();
			v.pop_back();
		}
	}
}

int nm31()
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
		v.push_back(i);
		nm31();
		v.pop_back();
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	nm3();
	return 0;
}