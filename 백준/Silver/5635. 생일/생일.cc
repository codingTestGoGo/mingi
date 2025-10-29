#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	vector<pair<pair<int, int>, pair<int, string>>> student(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> student[i].second.second;
		cin >> student[i].second.first;
		cin >> student[i].first.second;
		cin >> student[i].first.first;
	}

	sort(student.begin(), student.end());

	cout << student[n - 1].second.second << endl;
	cout << student[0].second.second;

	return 0;
}