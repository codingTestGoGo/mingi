#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
bool isUsed[10001];
int arr[10];
vector<int> numbers;

void DFS(int index, int StartIndex)
{
	if (m == index)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		//f (arr[0] == arr[m - 1] && arr[0] == numbers[n - 1]) return;
		cout <<"\n";
		return;
	}

	for (int i = StartIndex; i < n; i++)
	{
		if (isUsed[numbers[i]] == false)
		{
			arr[index] = numbers[i];
			DFS(index + 1, i);

		}
	}

	return;
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