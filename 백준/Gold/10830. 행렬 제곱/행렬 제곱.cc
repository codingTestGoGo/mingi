#include <iostream>
#include <vector>
#include <algorithm>

#define Mod 1000

using namespace std;

int n;
long long b;

struct Matrix
{
	int mat[5][5];

	// 기본생성자: 모든 원소를 0으로 초기화
	Matrix()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				mat[i][j] = 0;
			}
		}
	}

	//곱셈 연산자 오버로딩
	// 행렬끼리 *을 통해 곱할때 어떻게 동작할지 정의
	Matrix operator*(const Matrix& other) const
	{
		Matrix result;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int temp;
				for (int k = 0; k < n; k++)
				{
					result.mat[i][j] += mat[i][k] * other.mat[k][j];
					result.mat[i][j] = result.mat[i][j] % Mod;
				}
			}
		}

		return result;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> b; 

	Matrix nMat;
	Matrix resultMat;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> nMat.mat[i][j];
		}
		resultMat.mat[i][i] = 1;		// 대각선 성분만 1로 설정하여 단위행렬 생성
	}

	// 거듭제곱 로직
	// while문을 통해 함수호출 오버헤드 제거
	while (b > 0)
	{
		if (b %2 == 1)
		{
			resultMat = resultMat * nMat;	// 홀수일때만 결과에 nMat을 곱함
		}
		nMat = nMat * nMat;					// 행렬을 제곱하고 지수를 반으로 나눔
		b /= 2;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << resultMat.mat[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}