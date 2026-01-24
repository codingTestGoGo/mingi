#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int n, m;
vector<int> numbers;
set<string> isPrinted;
int arr[10];
bool isUsed[10];

void DFS(int index, int startNum)
{
	if (index == m)
	{
		string temp = "";
		for (int i = 0; i < m; i++)
		{
			temp += to_string(arr[i]) + " ";
		}

		if (isPrinted.count(temp) == 0)
		{
			isPrinted.insert(temp);
			cout << temp << "\n";
		} 

		return;
	}

	for (int i = startNum; i < n; i++)
	{
		arr[index] = numbers[i];
		DFS(index + 1, i);
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