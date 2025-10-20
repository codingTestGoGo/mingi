#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<char> arr;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string temp;
	cin >> temp;

	for (int i = 0; i < temp.length(); i++)
	{
		arr.push_back(temp[i]);
	}
	
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i];
	}

	return 0;
}