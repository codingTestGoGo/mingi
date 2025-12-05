#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

queue<int> arrSeries;
stack<int> arrStack;
vector<char> answer;
int n;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	vector<bool> arrIsUsed(n);
	queue<int> arrOneToN;
	int ntempInt;

	arrStack.push(0);
	fill(arrIsUsed.begin(), arrIsUsed.end(), false);

	for (int i = 0; i < n; i++)
	{
		cin >> ntempInt;
		arrSeries.push(ntempInt);
		arrOneToN.push(i + 1);
	}


	while (true)
	{
		//if (arrOneToN.empty() && !arrSeries.empty() && arrStack.top() != arrSeries.front())
		//{
		//	cout << "NO";
		//	return 0;
		//}

		if (arrOneToN.empty() && arrStack.top() == 0)
		{
			break;
		}

		else if (arrSeries.front() > arrStack.top())
		{
			arrStack.push(arrOneToN.front());
			arrOneToN.pop();
			answer.push_back('+');
			answer.push_back('\n');
			continue;
		}

		else if (arrSeries.front() == arrStack.top())
		{
			arrStack.pop();
			arrSeries.pop();
			answer.push_back('-');
			answer.push_back('\n');
			continue;
		}

		else
		{
			cout << "NO";
			return 0; 
		}

	}

	for (int i = 0; i < answer.size()-1; i++)
	{
		cout << answer[i];
	}

	return 0;

}

/*
* 1~n까지 오름차순으로 집어넣을 수 있다.
* 한번 넣은건 다시 넣을 수 없다.
*
* 1~n 까지 저장된 큐
* 뽑아야할 수열이 저장된큐
*
* n까지 다 넣었는데 탑에잇는 숫자가 뽑아야할 숫자가 아닌경우 바져나오다
*
*
*/