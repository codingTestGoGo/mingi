#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n;
int nExtremeValue;
int nRoundedAverage;
float sum = 0;
vector<int> problemDifficulty; 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int nTempInt;

	cin >> n;

	if (n == 0)
	{
		cout << 0; 
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> nTempInt;
		problemDifficulty.push_back(nTempInt);
	}

	sort(problemDifficulty.begin(), problemDifficulty.end());
	nExtremeValue = round(n * 15 / 100.0f);

	for (int i = 0; i < nExtremeValue; i++)
	{
		problemDifficulty[i] = 0;
		problemDifficulty[n - i - 1] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		sum += problemDifficulty[i];
	}

	nRoundedAverage = round(sum / (n - nExtremeValue * 2)); // 0/0을 반올림하면 오버플로우?? || 0/0 자체가 오버플로우가남

	cout << nRoundedAverage;
	
	return 0;
}