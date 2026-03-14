#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 1000

using namespace std;

int n;
long long b;
int nMatrix[5][5];
int resultMat[5][5];

void MatrixPower()
{
	int tempMat[5][5];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp = 0;
			for (int k = 0; k < n; k++)
			{
				temp += ((nMatrix[i][k] % MOD) * (nMatrix[k][j] % MOD)) % MOD;
			}
			tempMat[i][j] = temp % MOD;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			nMatrix[i][j] = tempMat[i][j];
		}
	}
}

void MatrixProductToResult()
{
	int tempMat[5][5];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp = 0;
			for (int k = 0; k < n; k++)
			{
				temp += ((resultMat[i][k] % MOD) * (nMatrix[k][j] % MOD)) % MOD;
			}
			tempMat[i][j] = temp % MOD;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			resultMat[i][j] = tempMat[i][j];
		}
	}
}

void DFS(long long power)
{

	if (power != 1 && power % 2 == 1)
	{
		MatrixProductToResult();
	}

	if (power == 1)
	{
		MatrixProductToResult();
		return;
	}

	MatrixPower();
	DFS(power / 2);

	return;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> b;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> nMatrix[i][j];
			if (i == j)
				resultMat[i][j] = 1;
			else
				resultMat[i][j] = 0;
		}
	}

	DFS(b);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << resultMat[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;

}