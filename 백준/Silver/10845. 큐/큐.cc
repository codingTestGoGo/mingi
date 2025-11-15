#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
queue<int> arrayQueue;

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	string tempString;
	int tempInt;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tempString;

		if (tempString == "push")
		{
			cin >> tempInt;
			arrayQueue.push(tempInt);
		}

		else if (tempString == "pop")
		{
			if (arrayQueue.empty())
			{
				cout << -1 << "\n";
			}

			else
			{
				cout << arrayQueue.front() << "\n";
				arrayQueue.pop();
			}
		}

		else if (tempString == "size")
		{
			cout << arrayQueue.size() << "\n";
		}

		else if (tempString == "empty")
		{
			if (arrayQueue.empty())
			{
				cout << 1 << "\n"; 
			}

			else
			{
				cout << 0 << "\n";
			}
		}

		else if (tempString == "front")
		{
			if (arrayQueue.empty())
			{
				cout << -1 << "\n";
			}
			
			else
			{
				cout << arrayQueue.front() << "\n";
			}
		}

		else if (tempString == "back")
		{
			if (arrayQueue.empty())
			{
				cout << -1 << "\n";
			}

			else
			{
				cout << arrayQueue.back() << "\n";
			}
		}
	}

	return 0;

}