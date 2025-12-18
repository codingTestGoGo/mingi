#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<int> adjInform[101];
int answer[101][101];
bool visitCheck[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; 

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int v;
			cin >> v;  
			if (v == 1)
			{
				adjInform[i].push_back(j);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (visitCheck[i] == true) continue;

		queue<int> connectedElement;
		//visitCheck[i] = true;
		//answer[i][i] = 1;
		connectedElement.push(i);

		while (connectedElement.empty() == false)
		{
			int cur = connectedElement.front();
			connectedElement.pop();
			for (auto nextNode : adjInform[cur])
			{
				if (visitCheck[nextNode] == true) continue;	
				visitCheck[nextNode] = true;
				answer[i][nextNode] = 1;
				connectedElement.push(nextNode); 
			}
		}

		fill(visitCheck, visitCheck + 101 * sizeof(bool), false);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

/*
* i에서 j로 가는 경우가 잇는 경우만 출력해야함
* => 연결요소로 체크되는 경우를 전부 잡아주면됨
* => 새로운i의 연결요소를 체크할 때마다 visitCheck를 클리어 해줄 필요가 있다.
* 
*/