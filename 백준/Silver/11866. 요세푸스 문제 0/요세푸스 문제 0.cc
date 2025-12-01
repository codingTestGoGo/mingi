#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 

	cin >> n >> k;

	vector<bool> isDeleted(n+1, false);
	vector<int> deleteOrder;
	int curIndex = 0;
	int nCanDeleteCnt = 0;

	while (deleteOrder.size() < n)
	{
		curIndex++;

		if (curIndex > n)
		{
			curIndex -= n;
		}

		if (nCanDeleteCnt < k && isDeleted[curIndex] == false)
		{
			nCanDeleteCnt++;
		}

		if (nCanDeleteCnt == k && isDeleted[curIndex] == false)
		{
			isDeleted[curIndex] = true;
			deleteOrder.push_back(curIndex);
			nCanDeleteCnt = 0;
		}
	}

	cout << "<";

	for (int i = 0; i < n-1; i++)
	{
		cout << deleteOrder[i] << ", ";
	}

	cout << deleteOrder[n-1] << ">";

	return 0;
}