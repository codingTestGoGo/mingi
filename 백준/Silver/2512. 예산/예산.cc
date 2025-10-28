#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m;				// 요청 개수, 총예산
vector<int> arr;

void Solve()
{
	long long nSumOfBudget = 0;
	int st = 1;			// 최소금액
	int en = arr[n-1] + 1;		// 최대금액
	int mid;

	for (int i = 0; i < n; i++)
	{
		nSumOfBudget += arr[i];
	}

	if (m >= nSumOfBudget)
	{
		cout << arr[n - 1];
		return;
	}

	while (st < en)
	{
		mid = (st + en + 1) / 2;
		nSumOfBudget = 0;
		
		//cout << "st: " << st << " en: " << en << endl;
		//cout << mid << endl;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] > mid)
			{
				nSumOfBudget += mid;
			}

			else
			{
				nSumOfBudget += arr[i];
			}
		}

		//cout << "총 예산: " << nSumOfBudget << endl << endl;;

		if (nSumOfBudget <= m)
		{
			st = mid;
		}

		else
		{
			en = mid -1;
		}
	}

	cout << st;

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 

	int temp;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	cin >> m;
	
	sort(arr.begin(), arr.end());

	Solve();

	return 0;
}


/*
* - 엣지 케이스
*	=> st의 값을 배열의 최소값으로 하는 경우 100 100 100 100 같이 동일한 금액만 있는경우
*      while문을 바로 빠져나와버리기 때문에 잘못된 값이 나온다.
*   => 모두 100이고 예산이 10이면 최소값이 예산보다 높아지기때문에틀리는것. => 1로 설정하자
*/