#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;

int arr[10];
bool isUsed[10];
vector<int> numbers;

void DFS(int index, int startNum)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	int lastTerm = -1;

	for (int i = startNum; i < n; i++)
	{
		if (isUsed[i] == false)
		{
			if (numbers[i] != lastTerm) 
			{
				isUsed[i] = true;
				arr[index] = numbers[i];

				lastTerm = numbers[i];
				DFS(index + 1, i + 1);
		

				isUsed[i] = false;

			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}
	sort(numbers.begin(), numbers.end());
	DFS(0, 0);
	return 0;
}