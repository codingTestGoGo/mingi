#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

int n, m; 
unordered_map<string, int> dict_EngToNum;
unordered_map<int, string> dict_NumToEng;
vector<string> arr;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	pair<int, string> tempIntToStr;
	pair<string, int> tempStrToInt;
	string tempStr;
	int tempInt;

	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		cin >> tempStr;

		dict_EngToNum.insert(make_pair(tempStr, i + 1));
		arr.push_back(tempStr);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> tempStr;

		if (isdigit(tempStr[0]))
		{
			cout << arr[stoi(tempStr)-1] << "\n";
		}
		else
		{
			cout << dict_EngToNum.find(tempStr)->second << "\n";
		}
	}
	
	return 0;
}