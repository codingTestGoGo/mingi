#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, r, c;
long long int answer = 0;

void Recursion(int n, int startX, int startY)
{
	if (n > 1)
	{
		//4 사분면
		if (r >= startX + n / 2 && c >= startY + n / 2)
		{
			answer += ((n * n) / 4) * 3;
			Recursion(n / 2, startX + n / 2, startY + n / 2);
			return;
		}
		// 3사분면
		if (r >= startX + n / 2 && c >= startY)
		{
			answer += (n * n) / 2;
			Recursion(n / 2, startX + n / 2, startY);
			return;
		}
		// 1사분면
		if (r >= startX && c >= startY + n / 2)
		{
			answer += (n *n) / 4;
			Recursion(n / 2, startX, startY + n/2);
			return;
		}
		// 2사분면
		if (r >= startX && c >= startY)
		{
			Recursion(n / 2, startX, startY);
			return;
		}
		return;
	}

	else if (startX == r && startY == c)
	{
		cout << answer;
		return;
	}

	answer++;
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r >> c;

	int temp = 1;
	for (int i = 0; i < n; i++)
	{
		temp *= 2;
	}
	n = temp;

	Recursion(n, 0, 0);
	return 0;
}