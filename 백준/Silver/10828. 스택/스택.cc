#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

stack<int> stackArray;
int n;

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);

	string tempStr;
	int tempInt;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tempStr;

		if (tempStr == "push")
		{
			cin >> tempInt;
			stackArray.push(tempInt);
			continue;
		}

		else if (tempStr == "pop")
		{
			if (stackArray.empty())
			{
				cout << -1 << "\n";
			}

			else
			{
				cout << stackArray.top() << "\n";
				stackArray.pop();
			}

			continue;
		}

		else if (tempStr == "size")
		{
			cout << stackArray.size() << "\n";
			continue; 
		}

		else if (tempStr == "empty")
		{
			if (stackArray.empty())
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}

		else if (tempStr == "top")
		{
			if (stackArray.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << stackArray.top() << "\n";
			}
		}
	}

	return 0;

}