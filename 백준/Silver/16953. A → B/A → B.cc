#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

#define MAX_LIMIT 1000000000

using namespace std;

long a, b;
bool isFound = false;

long AddOneToNum(long targetNum)
{
	char targetString[10];
	string temp = "";
	//itoa(targetNum, targetString, 10);
	sprintf(targetString, "%ld", targetNum);
	temp.append(targetString);
	temp += "1";
	return stol(temp);
}

void DFS(long targetNum, int depth)
{

	if (targetNum == b)
	{
		isFound = true;
		cout << depth + 1;
		return;
	}

	else if (targetNum > MAX_LIMIT || targetNum > b || isFound == true)
	{
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		switch (i) 
		{
		case 0:
			DFS(targetNum * 2, depth + 1);
			break;
		case 1:
			DFS(AddOneToNum(targetNum), depth + 1);
			break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	DFS(a, 0);

	if (isFound == false)
	{
		cout << -1; 
	}

	return 0;
}