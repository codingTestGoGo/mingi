#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int n;
stack<char> brakets;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string tempStr;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tempStr;

		for (int j = 0; j < tempStr.size(); j++)
		{
			if (brakets.empty())
			{
				brakets.push(tempStr[j]);
				continue;
			}

			else if (brakets.top() == '(' &&  tempStr[j] == ')')
			{
				brakets.pop();
				continue;
			}

			else
			{
				brakets.push(tempStr[j]);
				continue;
			}
			
		}

		if (brakets.empty())
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}

		while (!brakets.empty())
		{
			brakets.pop();
		}

	}

	return 0;

}