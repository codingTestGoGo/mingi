#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
bool isUsed[10001];
vector<int> nums;

void DFS(int index)
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

	for (int i = 0; i < n; i++)
	{
		if (isUsed[nums[i]] == false)
		{
			arr[index] = nums[i];
			isUsed[nums[i]] = true;
			DFS(index + 1);
			isUsed[nums[i]] = false;
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
		
		nums.push_back(temp);
	}

	sort(nums.begin(), nums.end());
	DFS(0);
	return 0;
}