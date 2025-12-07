#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int t, n;

unordered_map<string, int> arrClothes;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string tempStr1, tempStr2;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		int answer = 1;

		for (int j = 0; j < n; j++)
		{
			cin >> tempStr1 >> tempStr2;

			if (arrClothes.count(tempStr2) == 0)
			{
				arrClothes.insert(make_pair(tempStr2, 1));
			}

			else
			{
				arrClothes[tempStr2]++;
			}

		}

		for (const auto& pair : arrClothes)
		{
			answer *= pair.second + 1;
		}

		cout << answer - 1 << "\n";
		arrClothes.clear(); 
	}

	return 0;
}


/*
* 
* 의상은 중복되지 않는다.
* 한 종류의 의상이 몇 개있는지 알기만 하면된다.
* * n 종류의 의상이 잇는경우
*   => 1~n까지 각각의 경우의 수를 더해주어야 한다.
* * 하나의 종류를 입을지 안 입을지, 입는다면 무슨 옷을 입을지
*   => 1종류의 의류의 수 + 1 을 모두 곱해주면됨, 그리고 아무것도 안입는 경우를 제하기 위해 -1을 해주면 될 것.
*/