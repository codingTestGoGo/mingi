#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> subffix;
vector<char> arr[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string temp;
	cin >> temp; 

	for (int i = 0; i < temp.length(); i++)
	{
		subffix.push_back(temp.substr(i, temp.length()));
	}

	sort(subffix.begin(), subffix.end());

	for (int i = 0; i < subffix.size(); i++)
	{
		cout << subffix[i] << "\n";
	}
	return 0; 
}