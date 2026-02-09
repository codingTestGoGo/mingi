#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> burger;
	vector<int> beverage;

	for (int i = 0; i < 3; i++)
	{	
		int temp;
		cin >> temp;
		burger.push_back(temp);
	}

	for (int i = 0; i < 2; i++)
	{
		int temp;
		cin >> temp;
		beverage.push_back(temp);
	}


	sort(burger.begin(), burger.end());
	sort(beverage.begin(), beverage.end());

	int answer = burger[0] + beverage[0] -50;

	cout << answer;
	return 0; 
}