#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;					// 집개수 , 공유기 개수
vector<int> arrHomeCoord;


int CanInstallNum(int distance)
{
	int cnt = 1;
	int lastLocate = arrHomeCoord[0];

	for (int i = 1; i < arrHomeCoord.size(); i++)
	{
		int curLocate = arrHomeCoord[i];

		if (curLocate - lastLocate >= distance)
		{
			cnt++;
			lastLocate = curLocate;
		}
	}

	return cnt;
}

void Solve()
{
	int st = 1;											// 최소 거리
	int en = arrHomeCoord[n - 1] - arrHomeCoord[0] +1;		// 최대 거리 +1(upperbound 탐색이므로)

	while (st < en)
	{
		int mid = (st + en) / 2;

		if (CanInstallNum(mid) < c)
		{
			en = mid;
		}

		else
		{
			st = mid + 1;
		}

	}

	cout << st - 1;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int temp;
	
	cin >> n >> c; 

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arrHomeCoord.push_back(temp);
	}

	sort(arrHomeCoord.begin(), arrHomeCoord.end());

	Solve();

	return 0;
}