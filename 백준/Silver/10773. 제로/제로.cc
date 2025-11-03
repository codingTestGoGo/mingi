#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int temp;
	int sum = 0;

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> temp;

		if (temp != 0)
		{
			arr.push_back(temp);
		}

		else if (temp == 0 && arr.size() != 0)
		{
			arr.erase(arr.begin() + arr.size()-1);
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		sum += arr[i];
	}

	cout << sum;
}