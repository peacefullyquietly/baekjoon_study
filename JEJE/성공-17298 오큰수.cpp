#include <iostream>
#include<vector>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	vector<int> biggest, answer, k;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		k.push_back(m);
	}
	vector<int>::reverse_iterator a;
	for (a = k.rbegin(); a != k.rend(); a++)
	{
		while (!biggest.empty() && biggest.back() <= *a)
		{
			biggest.pop_back();
		}
		if (biggest.empty()) answer.push_back(-1);
		else answer.push_back(biggest.back());
		
		biggest.push_back(*a);
	}
	vector<int>::reverse_iterator b;
	for (b = answer.rbegin(); b != answer.rend(); b++)
	{
		cout << *b << " ";
	}
}