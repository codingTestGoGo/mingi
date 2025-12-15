#include<iostream>
#include<algorithm>
#include <queue>

using namespace std;

int n;

priority_queue<int, vector<int>, greater<>> plusQueue;
priority_queue<int, vector<int>, less<>> minusQueue;
vector<int> answer;

void PopValue()
{
	if (plusQueue.empty() && minusQueue.empty())
	{
		answer.push_back(0);
		return;
	}

	else if (plusQueue.empty())
	{
		//cout << minusQueue.top() << "\n";
		answer.push_back(minusQueue.top());
		minusQueue.pop();
		return;
	}

	else if (minusQueue.empty())
	{
		//cout << plusQueue.top() << "\n";
		answer.push_back(plusQueue.top());
		plusQueue.pop();
		return;
	}

	else
	{
		if (abs(minusQueue.top()) <= abs(plusQueue.top()))
		{		
			//cout << minusQueue.top() << "\n";
			answer.push_back(minusQueue.top());
			minusQueue.pop();
			return;
		}
		else
		{
			//cout << plusQueue.top() << "\n";
			answer.push_back(plusQueue.top());
			plusQueue.pop();
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	int nTempInt;

	for (int i = 0; i < n; i++)
	{
		cin >> nTempInt;

		if (nTempInt > 0) plusQueue.push(nTempInt);
		else if (nTempInt < 0) minusQueue.push(nTempInt);
		else if (nTempInt == 0) PopValue();
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}