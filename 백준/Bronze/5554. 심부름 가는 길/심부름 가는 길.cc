#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int backHomeTime, temp;
	cin >> temp;
	backHomeTime = temp;
	cin >> temp;
	backHomeTime += temp;
	cin >> temp;
	backHomeTime += temp;
	cin >> temp;
	backHomeTime += temp;

	cout << backHomeTime / 60 << "\n";
	cout << backHomeTime % 60 << "\n";

	return 0;
}