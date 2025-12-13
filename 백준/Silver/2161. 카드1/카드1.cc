#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> arr;
int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int nTempInt;

	for (int i = 0; i < n; i++)
	{
		arr.push(i+1); 
	}

	while (arr.empty() == false)
	{
		cout << arr.front() << " ";
		arr.pop();
		arr.push(arr.front());
		arr.pop(); 

		if (arr.size() == 1)
		{
			cout << arr.front();
			arr.pop();
		}
	}

	return 0;
}