#include <iostream>
#include <algorithm>
#include <queue>

using namespace std; 

int n; 
priority_queue<int, vector<int>, less<>> maxHeap;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int nTempInt;

	for (int i = 0; i < n; i++)
	{
		cin >> nTempInt;

		if (nTempInt == 0)
		{
			if (maxHeap.empty()) 
				cout << 0 << "\n";
			else
			{
				cout << maxHeap.top() << "\n";
				maxHeap.pop();
			}
		}

		else
		{
			maxHeap.push(nTempInt);
		}
	}

	return 0;

}