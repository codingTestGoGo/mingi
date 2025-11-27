#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	string tempStr;
	int endCnt = 0;
	int num = 665;

	while (endCnt != n)
	{
		num++;
		tempStr = to_string(num);
		
		for (int i = 0; i < tempStr.size() - 2; i++)
		{
			if (tempStr[i] == '6' && tempStr[i + 1] == '6' && tempStr[i + 2] == '6')
			{
				endCnt++;
				break;
			}
		}
	}

	cout << num;
	return 0;
}