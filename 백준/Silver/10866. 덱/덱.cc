#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int n;
deque<int> arrDeque;

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

		if (tempStr == "push_front")
		{
			cin >> tempInt;
			arrDeque.push_front(tempInt);
		}

		else if (tempStr == "push_back")
		{
			cin >> tempInt;
			arrDeque.push_back(tempInt);
		}

		else if (tempStr == "pop_front")
		{
			if (arrDeque.empty())
			{
				cout << -1 << "\n";
			}
			
			else
			{
				cout << arrDeque.front() << "\n";
				arrDeque.pop_front();
			}
		}

		else if (tempStr == "pop_back")
		{
			if (arrDeque.empty())
			{
				cout << -1 << "\n";
			}
			
			else
			{
				cout << arrDeque.back() << "\n";
				arrDeque.pop_back();
			}
		}

		else if (tempStr == "size")
		{
			cout << arrDeque.size() << "\n";
		}

		else if (tempStr == "empty")
		{
			if (arrDeque.empty())
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
			if (arrDeque.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << arrDeque.front() << "\n";
			}
		}

		else if (tempStr == "back")
		{
			if (arrDeque.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << arrDeque.back() << "\n";
			}
		}
	}

	return 0;
	
}