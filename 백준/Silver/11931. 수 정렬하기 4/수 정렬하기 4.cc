#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> arrN;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int nTempInt;
	for (int i = 0; i < n; i++)
	{
		cin >> nTempInt;

		arrN.push_back(nTempInt);
	}

	sort(arrN.begin(), arrN.end());

	for (int i = 0; i < n; i++)
	{
		cout << arrN[n - i - 1] << "\n";
	}
	
	return 0;
}