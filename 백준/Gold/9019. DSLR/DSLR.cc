#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int t;
int start, dist;
bool visitedNum[10000];

void BFS()
{
	queue<pair<int, string>> curNumAndCommand;
	string command;
	visitedNum[start] = true;
	curNumAndCommand.push(make_pair(start, ""));

	while (curNumAndCommand.empty() == false)
	{
		int curNum = curNumAndCommand.front().first;
		string curCommand = curNumAndCommand.front().second;

		curNumAndCommand.pop();
		if (curNum == dist)
		{
			cout << curCommand << "\n";
			return;
		}

		int nextNum;

		nextNum = (curNum * 2) % 10000;
		if (visitedNum[nextNum] == false)
		{
			visitedNum[nextNum] = true;
			curNumAndCommand.push(make_pair(nextNum, curCommand + "D"));
		}

		nextNum = (curNum == 0) ? 9999 : curNum - 1;
		if (visitedNum[nextNum] == false)
		{
			visitedNum[nextNum] = true;
			curNumAndCommand.push(make_pair(nextNum, curCommand + "S"));
		}

		nextNum = (curNum % 1000) * 10 + (curNum / 1000);
		if (visitedNum[nextNum] == false)
		{
			visitedNum[nextNum] = true;
			curNumAndCommand.push(make_pair(nextNum, curCommand + "L"));
		}

		nextNum = (curNum % 10) * 1000 + (curNum / 10);
		if (visitedNum[nextNum] == false)
		{
			visitedNum[nextNum] = true;
			curNumAndCommand.push(make_pair(nextNum, curCommand + "R"));
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> start >> dist;
		BFS();
		
		memset(visitedNum, false, sizeof(visitedNum));
	}

	return 0;
}