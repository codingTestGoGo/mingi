#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<int> arrA;
vector<int> arrB;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int nTempInt;
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> nTempInt;
		arrA.push_back(nTempInt);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> nTempInt;
		arrB.push_back(nTempInt);
	}

	sort(arrA.begin(), arrA.end()); 
	sort(arrB.begin(), arrB.end(), greater<>());

	for (int i = 0; i < n; i++)
	{
		sum += arrA[i] * arrB[i];
	}

	cout << sum;
	return 0;
}