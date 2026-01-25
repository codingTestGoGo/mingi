#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int n, s;
int arr[21];
unordered_map<int, bool> isUsed;
vector<int> numbers;
int answer = 0;

void DFS(int index, int startIndex, int length)
{
	if (index == length)
	{
		int sum = 0;
		for (int i = 0; i < length; i++)
		{
			sum += arr[i];
			//cout << arr[i] << " ";
		}
		if (sum == s)
		{
			answer++;
		}

		//cout << "\n";
		return;
	}

	for (int i = startIndex; i < n; i++)
	{
		arr[index] = numbers[i];
		DFS(index + 1, i + 1, length);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}

	for (int i = 1; i <= n; i++)
	{
		DFS(0,0, i);
	}
	
	cout << answer;
	return 0;
}