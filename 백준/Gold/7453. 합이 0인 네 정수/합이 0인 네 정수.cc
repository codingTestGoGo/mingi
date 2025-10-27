#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arrA;
vector<int> arrB;
vector<int> arrC;
vector<int> arrD;
vector<long> arrAPlusB;
vector<long> arrCPlusD;

int n;

void Solve()
{
	long answer = 0;
	int st = 0;
	int en = arrCPlusD.size() - 1;

	while (st < arrAPlusB.size() && en >-1)
	{
		long tempABValue = arrAPlusB[st];
		long tempCDValue = arrCPlusD[en];
		long sum = arrAPlusB[st] + arrCPlusD[en];

		if (sum< 0)
		{
			st++;
		}

		else if (sum > 0)
		{
			en--;
		}

		else
		{
			long cntAB = 0;
			long cntCD = 0;

			while ( st < arrAPlusB.size() && tempABValue == arrAPlusB[st])
			{
				st++;
				cntAB++;
			}

			while (en > -1 && tempCDValue == arrCPlusD[en])
			{
				en--;
				cntCD++;
			}

			answer += cntAB * cntCD;
		}

	}

	cout << answer;

}

void CombineArray(vector<int>& arrA, vector<int>& arrB, vector<long>& arrSum)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arrSum.push_back(arrA[i] + arrB[j]);
		}
	}

	sort(arrSum.begin(), arrSum.end());

	return;
}

void PrintArray(vector<int>& arrToPrint)
{
	for (int i = 0; i < arrToPrint.size(); i++)
	{
		cout << arrToPrint[i] << " ";
	}

	cout << endl;

	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int temp;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> temp;

			switch (j%4)
			{
			case 0:
				arrA.push_back(temp);
				break;
			case 1:
				arrB.push_back(temp);
				break;
			case 2:
				arrC.push_back(temp);
				break;
			case 3:
				arrD.push_back(temp);
				break;
			}
			
		}
	}

	sort(arrA.begin(), arrA.end());
	sort(arrB.begin(), arrB.end()); 
	sort(arrC.begin(), arrC.end());
	sort(arrD.begin(), arrD.end());

	//for (int j = 0; j < 4; j++)
	//{
	//	switch (j % 4)
	//	{
	//	case 0:
	//		PrintArray(arrA);
	//		break;
	//	case 1:
	//		PrintArray(arrB);
	//		break;
	//	case 2:
	//		PrintArray(arrC);
	//		break;
	//	case 3:
	//		PrintArray(arrD);
	//		break;
	//	}
	//}

	CombineArray(arrA, arrB, arrAPlusB);
	CombineArray(arrC, arrD, arrCPlusD); 

	Solve();
}