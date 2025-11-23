#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int n;
int arrNumOfTang[10] = { 0, };
vector<int> TangStructure; 
int CountTangKind()
{
	int nTangKind = 0;

	for (int i = 1; i < 10; i++)
	{
		if( arrNumOfTang[i] != 0)
			nTangKind++;
	}

	return nTangKind;
}

void PrintNumOfTangs()
{
	for (int i = 1; i < 11; i++)
	{
		cout << arrNumOfTang[i] << " ";
	}

	cout << endl;
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tempInt;
	int st = 0;
	int en = 0;

	int answer = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tempInt;
		TangStructure.push_back(tempInt);
	}

	for (int i = 0; i < n; i++)
	{
		arrNumOfTang[TangStructure[i]]++;
		//en++;
		while (CountTangKind() > 2)
		{
			arrNumOfTang[TangStructure[st]]--;
			st++;
		}

		answer = max(answer, i - st + 1);

	}

	cout << answer;


	return 0;
	
}



/*
*  * 탕후루의 종류는 10개밖에 없다. => 배열로 개수를 관리하자
* 
*  * 앞 뒤에서 한개 씩 빼준다고 할 때 빼는 시작 순서에 따라서 개수가 달라지는 경우의 수는 어떻게 해결 할 것인가
*   - 1123 의 경우 앞을 먼저 빼서 123 이되면 12가 답이되고 뒤를 먼저빼서 112가 돼면 112가 답이다
*		=> 양 끝의 탕후루의 개수를 비교해서 적은 쪽을 먼저 빼버리w자
*		=> 11231 같은 경우를 처리할 수 없ㄷ
* 
*  * 빼는게 아니라 꽂는다는 방식으로 생각해야함
*   - 투 포인터로 st, en 을 모두 0에 넣는다
*	- en을 증가시키면서 탕후루의 종류를 증가시킨다
*   - 종류가 2개 이상인 경우 st 를 증가시키면서 탕후를 뺀다.
*   - en이 끝에 도달하면 사이즈를 출력
*/