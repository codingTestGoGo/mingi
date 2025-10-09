#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 
typedef long long ll;

int m, n;						// 조카 수, 과자 수
vector<ll> arrSnackLengths;

ll FindUpperBound()
{
	ll st = 0;
	ll en = arrSnackLengths[n - 1];
	ll mid, snackCnt;

	while (st < en)
	{
		mid = (st + en + 1) / 2;
		snackCnt = 0;

		for (int i = 0; i < n; i++)
		{
			snackCnt += arrSnackLengths[i] / mid;
		}

		//cout << "cnt : " << snackCnt << " st: " << st << " en: " << en << " mid : " << mid << endl;

		if (snackCnt < m )		// 조카수보다 적다 == 과자가 넘 길다 => 길면 일단 무조건 잘라야돼 
		{
			en = mid - 1;
		}

		if (snackCnt >= m )		// 조카수보다 많거나 같아 == 과자가 짧거나 같아
		{
			st = mid;
		}
	}

	cout << st;
	return st;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll temp;
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arrSnackLengths.push_back(temp);
	}

	sort(arrSnackLengths.begin(), arrSnackLengths.end());
	FindUpperBound();

	return 0;
}


/*
* 가장 긴 과자를 en, 1 (가장 짧게 자를 수 있는 경우)을 st로 설정해서 모든 과자를 mid로 나눠서 m을 만족하는 upperbound찾기
*/