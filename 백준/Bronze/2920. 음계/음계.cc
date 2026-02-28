#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[9];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i < 9; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i < 9; i++)
	{
		if (i != arr[i])
		{
			break;
		}

		if (i == 8)
		{
			cout << "ascending";
			return 0;
		}
	}

	for (int i = 1; i < 9; i++)
	{
		if ((9-i) != arr[i])
		{
			break;
		}

		if (i == 8)
		{
			cout << "descending";
			return 0;

		}
	}

	cout << "mixed";
	return 0;

}