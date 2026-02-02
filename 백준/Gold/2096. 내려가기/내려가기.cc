#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxArr[3];
int minArr[3];
int maxTemp[3];
int minTemp[3];
int input[3];
int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int minSelect;
	int maxSelect;

	for (int i = 0; i < n; i++)
	{
		cin >> input[0] >> input[1] >> input[2];

		if (i == 0)
		{
			for (int j = 0; j < 3; j++)
			{
				maxArr[j] = minArr[j] = maxTemp[j] = minTemp[j] = input[j];
			}
			continue;	
		}

		minArr[0] = input[0] + min(minTemp[0], minTemp[1]);
		maxArr[0] = input[0] + max(maxTemp[0], maxTemp[1]);

		minArr[1] = input[1] + min({ minTemp[0], minTemp[1], minTemp[2] });
		maxArr[1] = input[1] + max({ maxTemp[0], maxTemp[1], maxTemp[2] });

		minArr[2] = input[2] + min(minTemp[1], minTemp[2]);
		maxArr[2] = input[2] + max(maxTemp[1], maxTemp[2]);

		for (int j = 0; j < 3; j++)
		{
			minTemp[j] = minArr[j];
			maxTemp[j] = maxArr[j];
		}
	}

	cout << max({ maxArr[0], maxArr[1], maxArr[2] }) << " " << min({ minArr[0], minArr[1], minArr[2] });
	return 0;
}