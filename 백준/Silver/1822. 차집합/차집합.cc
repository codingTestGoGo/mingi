#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nA, nB;
vector<int> arrA, arrB, arrResult;

bool BinarySearch(int target, vector<int>& arr)
{
	int st = 0;
	int en = arr.size();
	int mid;

	while (st < en)
	{
		mid = (st + en) / 2;

		//cout << "st: " << st << " en " << en << " mid: " << mid << endl;

		if (target > arr[mid])
		{
			st = mid + 1;
		}
		
		else if (target < arr[mid])
		{
			en = mid;
		}

		else if (target == arr[mid])
		{
			//cout << arr[mid];
			return true;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int nTemp;
	int cnt = 0;

	cin >> nA >> nB;

	for (int i = 0; i < nA; i++)
	{
		cin >> nTemp;
		arrA.push_back(nTemp);
	}

	for (int i = 0; i < nB; i++)
	{
		cin >> nTemp;
		arrB.push_back(nTemp);
	}

	sort(arrA.begin(), arrA.end());
	sort(arrB.begin(), arrB.end());

	for (int i = 0; i < nA; i++)
	{
		if (BinarySearch(arrA[i], arrB) == false)
		{
			cnt++;
			arrResult.push_back(arrA[i]);
		}
	}

	cout << cnt << endl;

	for (int i = 0; i < arrResult.size(); i++)
	{
		cout << arrResult[i] << " "; 
	}

	return 0;
}