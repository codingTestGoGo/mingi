#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int paperInform[129][129];
int paperCnt[2];

void CheckPaperPerfect(int n, int startI, int startJ)
{
	int paperColor = paperInform[startI][startJ];

	if (n == 1)
	{
		paperCnt[paperColor]++;
		return;
	}

	for (int i = startI; i < startI + n; i++)
	{
		for (int j = startJ; j < startJ + n; j++)
		{
			if (paperInform[i][j] != paperColor)
			{
				CheckPaperPerfect(n / 2, startI, startJ);
				CheckPaperPerfect(n / 2, startI + n / 2, startJ);
				CheckPaperPerfect(n / 2, startI, startJ + n / 2);
				CheckPaperPerfect(n / 2, startI + n / 2, startJ + n / 2);
				return;
			}
		}
	}

	paperCnt[paperColor]++;
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		//paperInform[i].push_back(0);
		for (int j = 1; j <= n; j++)
		{
			int temp;
			cin >> temp;
			
			//paperInform[i].push_back(temp);
			paperInform[i][j] = temp;
		}

	}

	CheckPaperPerfect(n, 1, 1);
	cout << paperCnt[0] << "\n";
	cout << paperCnt[1] << "\n";

	return 0;
}

