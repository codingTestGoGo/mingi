#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

ll n;
ll result = 3000000000;
vector<int> arr;
vector<ll> arrAnswer(3);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int temp; 
	int st, en;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	for (int i = 1; i < n; i++)
	{
		ll target = arr[i];

		st = 0;
		en = n - 1;
		
		while (st < en)
		{
			ll sum = target + arr[st] + arr[en];

			if (result != min(abs(sum), result))
			{
				if (st == i || en == i)
				{
					break;
				}

				result = abs(sum);
				arrAnswer[0] = arr[st];
				arrAnswer[1] = arr[en];
				arrAnswer[2] = arr[i];
			}

			if (sum > 0)
			{
				en += -1;
			}
			else
			{
				st += 1;
			}
		}
	}

	sort(arrAnswer.begin(), arrAnswer.end());
	cout << arrAnswer[0] << " " << arrAnswer[1] << " " << arrAnswer[2];
}

/*
*  - 투 포인터로 조이면서 그 사이의 숫자를 선형탐색하는 경우 => O(n^3) ... 안될거같은데
*  => 가능, but, 투포인터 조이는 동안 내부에서 3번째 수를 선정하려고하면 놓치는 조합이 생긴다.
*  => 외부에서 3번째 수를 설정하고 투포인터로는 가지 조합의 수만 설정, 그리고 외부 수와 겹치는경우 생략해주면 됀다.
*  => st, en을 수정할 때의 기준은 arr[st] + arr[en] 이 아니라 target까지 더한 세 수의 합을 기준으로 옮겨야 한다
*/