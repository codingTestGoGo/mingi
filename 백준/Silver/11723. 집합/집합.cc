#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int m;
unordered_map<int, bool> setS;
vector<pair<int, bool>> arrSet(21);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tempInt;
	string tempStr;

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> tempStr;

		if (tempStr == "add")
		{
			cin >> tempInt;
			arrSet[tempInt].second = true;
		}

		else if (tempStr == "remove")
		{
			cin >> tempInt;
			arrSet[tempInt].second = false;
		}

		else if (tempStr == "check")
		{
			cin >> tempInt;

			if (arrSet[tempInt].second == true)
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}

		else if (tempStr == "toggle")
		{
			cin >> tempInt;

			if (arrSet[tempInt].second == true)
			{
				arrSet[tempInt].second = false;
			}
			else
			{
				arrSet[tempInt].second = true;
			}
		}

		else if (tempStr == "all")
		{
			
			for (int i = 1; i < 21; i++)
			{
				arrSet[i].second = true;
			}
		}

		else if (tempStr == "empty")
		{
			for (int i = 1; i < 21; i++)
			{
				arrSet[i].second = false;
			}
		}
	}

	return 0;
}