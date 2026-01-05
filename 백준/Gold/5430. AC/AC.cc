#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int t;
deque<int> arr;
char command[100001];

void Parse(string target, int targetLen)
{
	if (targetLen == 2) return;
	string temp = "";
	int curPos = 1;
	for (int i = 0; i < targetLen; i++)
	{
		if (isdigit(target[i]) == true)
		{
			temp += target[i];
		}
		else
		{
			if (temp.empty() == false)
			{
				arr.push_back(stoi(temp));
				temp = "";
			}
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int numLen;
		int commandLen;
		bool isError = false;
		bool isReverse = false;

		string tempCommand, tempArr;

		cin >> tempCommand;
		strcpy(command, tempCommand.c_str());
		commandLen = tempCommand.size();

		cin >> numLen;
		cin >> tempArr;

		Parse(tempArr, tempArr.size());

		for (int j = 0; j < commandLen; j++)
		{
			if (command[j] == 'R')
			{
				isReverse = !isReverse;
				continue;
			}
			else if (command[j] == 'D' && arr.empty() != true)
			{
				if (isReverse == true)
					arr.pop_back();
				else
					arr.pop_front();
				continue;
			}
			isError = true;
		}

		if (isError == true)
		{
			cout << "error\n";
		}
		else
		{
			int len = arr.size();
			cout << "[";
			for (int j = 0; j < len; j++)
			{
				if (isReverse == true)
				{
					if (j == len - 1)
						cout << arr.back();
					else
						cout << arr.back() << ",";
					arr.pop_back();
				}
				else
				{
					if (j == len - 1)
						cout << arr.front();
					else
						cout << arr.front() << ",";
					arr.pop_front();
				}
			}
			cout << "]\n";
		}

		while (arr.empty() == false)
		{
			arr.pop_front();
		}
	}

	return 0;
}