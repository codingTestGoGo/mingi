#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<string, string> sitePassword;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string tempStr1;
	string tempStr2;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> tempStr1 >> tempStr2;

		sitePassword.insert(make_pair(tempStr1, tempStr2)); 
	}

	for (int i = 0; i < m; i++)
	{
		cin >> tempStr1;

		cout << sitePassword.find(tempStr1)->second << "\n";
	}

	return 0;
}