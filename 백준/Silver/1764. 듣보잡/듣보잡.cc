#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, bool> neverHear;
vector<string> neverHearListen;
int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string tempStr;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> tempStr;
		neverHear.insert(make_pair(tempStr, true));
	}

	for (int i = 0; i < m; i++)
	{
		cin >> tempStr;

		if (neverHear.count(tempStr)) 
		{
			neverHearListen.push_back(tempStr);
		}
	}

	sort(neverHearListen.begin(), neverHearListen.end());
	cout << neverHearListen.size() << "\n";

	for (int i = 0; i < neverHearListen.size(); i++)
	{
		cout << neverHearListen[i] << "\n";
	}

	return 0;
}