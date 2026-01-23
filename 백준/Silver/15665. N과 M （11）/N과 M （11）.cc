#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int n, m;

int arr[10];
vector<int> numbers;
unordered_map<string, bool> isUsed;

void DFS(int index)
{
	if (index == m)
	{
		string temp = "";
		for (int i = 0; i < m; i++)
		{
			temp += to_string(arr[i]) + " ";
		}

		if (isUsed.count(temp) == 0)
		{
			cout << temp;
			cout << "\n";
			isUsed.insert(make_pair(temp, false));
		}

		
		return;
	}


	for (int i = 0; i < n; i++)
	{
		arr[index] = numbers[i];
		DFS(index + 1);
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

	DFS(0); 

	return 0;
}