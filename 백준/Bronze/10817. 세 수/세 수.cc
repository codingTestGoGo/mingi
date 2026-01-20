#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);

	for (int i = 0; i < 3; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	cout << arr[1];

	return 0;
}