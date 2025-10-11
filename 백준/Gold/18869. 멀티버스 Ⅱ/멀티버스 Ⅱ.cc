#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;				// 우주 개수, 행성 개수
vector<vector<int>> arrSpace;


void Compress(vector<int>& space)
{
	vector<int> temp(space.size());
	int len = space.size();
	copy(space.begin(), space.end(), temp.begin());
	sort(temp.begin(), temp.end());

	for (int i = 0; i < len; i++)
	{
		space[i] = lower_bound(temp.begin(), temp.end(), space[i]) - temp.begin();
	}

	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int temp;
	int evenCnt = 0;
	cin >> m >> n;

	arrSpace.resize(m);

	for (int i = 0; i < m; i++)			// 우주 벡터 값 초기화
	{
		arrSpace[i].reserve(n);

		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			arrSpace[i].push_back(temp);
		}

		Compress(arrSpace[i]);				// 각 우주 좌표 압축
		arrSpace[i].erase(unique(arrSpace[i].begin(), arrSpace[i].end()), arrSpace[i].end()); // 행성 중복 제거
	}


	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (arrSpace[i].size() != arrSpace[j].size())
			{
				continue;
			}
			
			else
			{
				for (int k = 0; k < arrSpace[i].size(); k++)
				{
					if (arrSpace[i][k] != arrSpace[j][k])
					{
						break;
					}

					if (k == arrSpace[i].size() - 1)
					{
						evenCnt++;
					}
				}
			}
		}
	}

	cout << evenCnt;

	return 0;

}

/*
*  한줄에서 나올 수 있는 모든 범위 a1~an 의 관계 n x n 개 에 대해서 모든 우주와 관계가 똑같아야 한다.
*  nxn에 대해서 m 번 검사를 해야함 => nxnx m
* 첫 번째 우주에서 중복을 제거하는경우... 행성의 개수가 틀려지고 밀리면서 결과값이 전혀 달라질 수 잇는데..
* 똑같은 인덱스에서 제거가 되지 않으면 의미가 없다 .. 
*  => 하지만 균등한 우주가 되려면 중복된 인덱스를 제거 했을때 똑같은 인덱스에 중복된 숫자가 있어야함
*  => 첫번째 우주의 중복을 제거하고, 다른 우주와 비교를 하기 전에 사이즈가 다르면 스킵해도 괜찮다.
* 
* 이분 탐색을 하려면 정렬이 되어야 하는데, 정렬을 하면 우주가 흐트러진다. .. 
*  균등한 우주를 모두 정렬을 하면, 그럼에도 균등한가? => 아님
* 
* 
* 정렬을 하지 않고 unique로 중복만제거, erase로 지운다.
*  => 크기가 다른 우주들은 무조건 균등하지 않다.
* 
* 크기가 같은 경우 정석적으로 검사를 실행한다 => 최악의 경우 1~m까지의 합 * 1~n까지의 합..  m^2n^2
* => 다만 n은 10000, m 은 300  => 시간 초과
* 
* 
* <좌표 압축>
*  - 복사 -> 정렬 -> 중복제거
*  - 기존 배열의 값을 temp 백터에 복사, 정렬, 중복 제거 후 기존배열의 값들을 temp에서 이분탐색으로 찾는다.
*    찾았다면 해당 값의 인덱스로 기존 배열의 값을 바꾼다.
* 
*  - 위의 방식으로 압축된 값이 하나라도 다르다면 균등하다 할 수 없다.
*    => 우주마다 다를 수 있는 행성 각각의 크기를 0~n으로 통일할 수 있다는 것에 의의가 있음
*    => O(n) 시간 안에 두 우주가 균등한지 검사할 수 있다
* 
* 
* <Iterator>
*  - c++의 stl 컨테이너에서 포인터처럼 작동하는 객체
*  - vector<int>::iterator 는 int * 와 거의 동일하다
*  - upper_bound 와 같이 찾은 값의 위치를 반환하는 경우, 인덱스가 아니라 iterator를 반환하는 것이기 때문에 실제 인덱스를
*    알고 싶다면, 반환값에 begin() 값을 빼 주어야 한다.
* 
*/