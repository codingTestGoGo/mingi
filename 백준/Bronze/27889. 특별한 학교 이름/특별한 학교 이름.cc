#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string temp;
	cin >> temp;
	if (temp == "NLCS")
	{
		cout << "North London Collegiate School";
	}
	else if (temp == "BHA")
	{
		cout << "Branksome Hall Asia";
	}
	else if (temp == "KIS")
	{
		cout << "Korea International School";
	}
	else if (temp == "SJA")
	{
		cout << "St. Johnsbury Academy";
	}
	return 0;
}