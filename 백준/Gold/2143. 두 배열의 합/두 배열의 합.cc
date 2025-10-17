#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m;
vector<int> arrA;
vector<int> arrB;
vector<long long> arrSumA;
vector<long long> arrSumB;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int temp;
	long long answer = 0;

	cin >> t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arrA.push_back(temp);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		arrB.push_back(temp);
	}

	// 배열의 모든 부분 합을 구해서 sum에 넣는다.
	for (int i = 0; i < n; i++)
	{
		long long sum = arrA[i];
		arrSumA.push_back(sum);

		for (int j = i+1; j < n; j++)
		{
			sum += arrA[j];
			arrSumA.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++)
	{
		long long sum = arrB[i];
		arrSumB.push_back(sum);

		for (int j = i+1; j < m; j++)
		{
			sum += arrB[j];
			arrSumB.push_back(sum);
		}
	}

	sort(arrSumA.begin(), arrSumA.end());
	sort(arrSumB.begin(), arrSumB.end());

	for (int i = 0; i < arrSumA.size(); i++)
	{
		int target = t - arrSumA[i];

		answer += upper_bound(arrSumB.begin(), arrSumB.end(), target) - lower_bound(arrSumB.begin(), arrSumB.end(), target);

	}

	cout << answer;

	return 0;

}