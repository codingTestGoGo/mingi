#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int twoCnt = 0;
	int fiveCnt = 0;
	int tempInt;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		tempInt = i;
		while (1)
		{
			if (tempInt % 2 == 0)
			{
				tempInt /= 2;
				twoCnt++;
				continue;
			}

			else if (tempInt % 5 == 0)
			{
				tempInt /= 5;
				fiveCnt++;
				continue;
			}

			else break;
		}
	}

	int answer = min(twoCnt, fiveCnt);

	cout << answer; 

	return 0;
}