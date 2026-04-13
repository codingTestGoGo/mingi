#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, m, n, x, y;

int GetLCD(int a, int b)
{
	int gcd = 1;
	int divider = 2;
	while (1)
	{
		if (divider > a || divider > b) break;
		if (a % divider == 0 && b % divider == 0)
		{
			gcd *= divider;
			a /= divider;
			b /= divider;
			continue;
		}
		else
		{
			divider++;
		}
	}

	return gcd * a * b;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> m >> n >> x >> y;
		int mnLCD = GetLCD(m, n);
		int index = 0;
		while (1)
		{
			int curDate = x + (index * m);
			if (curDate > mnLCD)
			{
				cout << -1 << "\n"; 
				break;
			}
			else if (curDate % n == y || (curDate % n == 0 && n == y))
			{
				cout << curDate << "\n";
				break;
			}
			index++;
		}
	}

	return 0;
		
}

