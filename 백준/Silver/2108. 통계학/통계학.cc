#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arrNumbers;
vector<int> arrMostFrequentValues;
int fArithmeticMean;
int nMedianValue;
int nMostFrequentValue;
int nRangeValue;

vector<int> arrExistingNumCnt(8001);
int nMaxAppearCnt = 0;

void GetMostFrequentValue()
{
	for (int i = 0; i < arrExistingNumCnt.size(); i++)
	{
		nMaxAppearCnt = max(nMaxAppearCnt, arrExistingNumCnt[i]);
	}

	for (int i = 0; i < arrExistingNumCnt.size(); i++)
	{
		if (nMaxAppearCnt == arrExistingNumCnt[i])
		{
			if (i > 4000)
				arrMostFrequentValues.push_back(-(i-4000));
			else
				arrMostFrequentValues.push_back(i);
		}
	}

	if (arrMostFrequentValues.size() > 1)
	{
		sort(arrMostFrequentValues.begin(), arrMostFrequentValues.end());
		nMostFrequentValue = arrMostFrequentValues[1];
	}
	else
	{
		nMostFrequentValue = arrMostFrequentValues[0];
	}

	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin >> n;

	fill(arrExistingNumCnt.begin(), arrExistingNumCnt.end(), 0);

	int nTempInt;
	int nSum = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> nTempInt;
		arrNumbers.push_back(nTempInt);
		nSum += nTempInt;

		if (nTempInt >= 0) arrExistingNumCnt[nTempInt]++;
		else arrExistingNumCnt[-nTempInt + 4000]++;
	}

	sort(arrNumbers.begin(), arrNumbers.end());

	nMedianValue = arrNumbers[n / 2];
	fArithmeticMean = round(floor((float(nSum) / n) * 10) / 10 );		// 10을 곱해서 둘째자리버리고 10을 다시 나눠서 첫째자리 반올림
	GetMostFrequentValue(); 

	if (arrNumbers[0] * arrNumbers[arrNumbers.size() -1] > 0)
	{
		nRangeValue = abs(arrNumbers[arrNumbers.size() - 1] - arrNumbers[0]);
	}
	else
	{
		nRangeValue = abs(arrNumbers[0]) + abs(arrNumbers[arrNumbers.size() - 1]);
	}

	cout << fArithmeticMean << "\n";
	cout << nMedianValue << "\n";
	cout << nMostFrequentValue << "\n";
	cout << nRangeValue;

	return 0; 
}

/*
* 4천 크기의 배열을 2개 만든다
* 특정 값이 나오러때마다 배열의 인덱슬르 ++
* 배열을 1회 순회하면서 가장 큰 값을 얻는다.
* 2회째 순회할때 가장큰 값과 동일한 값들을 벡터에 집어넣는다.
* 백터의 사이즈가 2이상이라면 정렬하고 두번째로 작은 값을 출력한다.
* 
* 처음값과 끝값의 부호가 같은 경우 뺴서 절대값을 취하고 다른 경우 각각의 절대값을 더한다
*/