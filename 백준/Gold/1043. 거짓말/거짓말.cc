#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> knowTruth;
vector<int> partyList[50];
bool isKnow[51];
bool checkedParty[51];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int trueCnt;
	cin >> n >> m;
	cin >> trueCnt;

	// 진아 등록
	for (int i = 0; i < trueCnt; i++)
	{
		int temp;
		cin >> temp;
		knowTruth.push_back(temp);
		isKnow[temp] = true;
	}

	// 파티리스트 등록
	for (int i = 0; i < m; i++)
	{
		int peopleCnt;
		cin >> peopleCnt;

		for (int j = 0; j < peopleCnt; j++)
		{
			int temp;
			cin >> temp;
			partyList[i].push_back(temp);
		}
	}

	bool readyToParty = false;

	// 진아의 수가 갱신되지 않을때까지 파티를 순회
	while (readyToParty == false)
	{
		bool knowerIsAdded = false;

		for (int i = 0; i < m; i++)
		{
			int peopleCnt = partyList[i].size();
			bool shouldBeTrue = false;

			for (auto people : partyList[i])
			{
				if (isKnow[people] == true && checkedParty[i] == false)
				{
					checkedParty[i] = true;
					shouldBeTrue = true;
					break;
				}
			}

			if (shouldBeTrue == true)
			{
				knowerIsAdded = true;
				for (auto people : partyList[i])
				{
					isKnow[people] = true;
				}
			}
		}

		if (knowerIsAdded == false)
		{
			readyToParty = true;
		}
	}

	int answer = 0;
	for (int i = 0; i < m; i++)
	{
		if (isKnow[partyList[i][0]] == false)
		{
			answer++;
		}
	}
	
	cout << answer;
	return 0;
}