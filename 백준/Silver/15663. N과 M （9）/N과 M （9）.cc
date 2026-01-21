#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

int m, n;
unordered_map<string, bool> usedSeries;
bool isUsed[10001];
int arr[10];
vector<int> numbers;

void DFS(int index)
{
	if (m == index)
	{
		string temp = "";

		for (int i = 0; i < m; i++)
		{
			temp += to_string(arr[i]) + " ";
		}
		
		if (usedSeries.count(temp) == 0)
		{
			usedSeries.insert(make_pair(temp, true));
			cout << temp << "\n";
		}
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (isUsed[i] == false)
		{
			isUsed[i] = true;
			arr[index] = numbers[i];
			DFS(index + 1);
			isUsed[i] = false;
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

	DFS(0);
	return 0;
	
}