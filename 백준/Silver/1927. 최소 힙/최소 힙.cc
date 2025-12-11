#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> arrNaturalNumbers;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; 

	int nTempInt;

	for (int i = 0; i < n; i++)
	{
		cin >> nTempInt;
		if (nTempInt != 0)
		{
			arrNaturalNumbers.push(nTempInt);
		}

		else if (nTempInt == 0)
		{
			if (arrNaturalNumbers.empty())
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << arrNaturalNumbers.top() << "\n";
				arrNaturalNumbers.pop();
			}
		}
	}

	return 0; 

}