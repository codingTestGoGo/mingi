#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

int p1[3];
int p2[3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	vector<int> arr;
	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(c);
	sort(arr.begin(), arr.end());
	cout << arr[0] << " " << arr[1] << " " << arr[2];

	return 0;
}