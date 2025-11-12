#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int n;
map<string, string, greater<string>> employeeStat;

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	string tempA, tempB; 

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tempA >> tempB;

		if (tempB == "enter")
			employeeStat.insert(make_pair(tempA, tempB));
		else
			employeeStat.erase(tempA);
	}

	for (auto it :employeeStat )
	{
		cout << it.first << "\n";
	}

	return 0;
}