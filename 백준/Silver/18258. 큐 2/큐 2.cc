#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
queue<int> arrQueue;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tempInt;
	string tempStr;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tempStr;

		if (tempStr == "push")
		{
			cin >> tempInt;
			arrQueue.push(tempInt);
			continue;
		}

		else if (tempStr == "pop")
		{
			if (arrQueue.empty())
			{
				cout << -1 << "\n";
			}

			else
			{
				cout << arrQueue.front() << "\n";
				arrQueue.pop();
			}

			continue; 
		}

		else if (tempStr == "size")
		{
			cout << arrQueue.size() << "\n";
		}

		else if (tempStr == "empty")
		{
			if (arrQueue.empty())
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}

		else if (tempStr == "front")
		{
			if (arrQueue.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << arrQueue.front() << "\n";
			}
		}

		else if (tempStr == "back")
		{
			if (arrQueue.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << arrQueue.back() << "\n";
			}
		}
	}

	return 0;
}