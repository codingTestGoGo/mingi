#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

stack<char> arrStack;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string tempStr;

	while (1)
	{
		getline(cin, tempStr);

		if (tempStr == ".")
		{
			break;
		}

		for (int i = 0; i < tempStr.size(); i++)
		{
			if (tempStr[i] == '[' || tempStr[i] == '(')
			{
				arrStack.push(tempStr[i]);
			}

			else if ( !arrStack.empty() &&
					(tempStr[i] == ']' && arrStack.top() == '[' ||
				     tempStr[i] == ')' && arrStack.top() == '('))
			{
				arrStack.pop();
			}

			else if (tempStr[i] == ']' || tempStr[i] == ')')
			{
				arrStack.push(tempStr[i]);
			}
		}

		if (arrStack.empty())
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}

		while (!arrStack.empty())
		{
			arrStack.pop();
		}
		
	}

	return 0;
}
