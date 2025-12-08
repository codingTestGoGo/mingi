#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int n, k;
vector<int> arrCoinValue;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;

	int nTempInt;
	int nCurMoney = 0;
	int nCointCnt = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> nTempInt;
		arrCoinValue.push_back(nTempInt); 
	}

	sort(arrCoinValue.begin(), arrCoinValue.end(), greater<>());

	while (nCurMoney < k)
	{
		for (int i = 0; i < n; i++)
		{
			if (arrCoinValue[i] > k - nCurMoney)
			{
				continue;
			}
			else
			{
				nCurMoney += arrCoinValue[i];
				nCointCnt++;
				break;
			}
		}
	}

	cout << nCointCnt << "\n";
	return 0;
}

/*
*  * 해당 동전 문제가 그리디로 풀리는 이유는 동전의 단위가 배수로 주어지기에 가능한것을 명심
*/