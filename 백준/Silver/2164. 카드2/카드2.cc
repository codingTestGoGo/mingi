#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
queue<int> arrQueue;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i < n+1; i++)
	{
		arrQueue.push(i);
	}


	while (arrQueue.size() > 1)
	{
		arrQueue.pop();
		arrQueue.push(arrQueue.front());
		arrQueue.pop();
	}

	cout << arrQueue.front();

	return 0;
}