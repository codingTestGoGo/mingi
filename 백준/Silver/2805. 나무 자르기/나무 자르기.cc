#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;		// n : 나무의 수 , m: 나무의 길이
vector<long long> arrTreeList;

void Solve()
{
	int st = 0;						  // 자를 나무의 최소 높이 
	int en = arrTreeList[n - 1] ;  // 현재 배열에서 존재하는 최대 나무 높이 + 1	
	long long  mid, treeLength;

	while (st < en)
	{
		mid = (st + en +1) / 2;
		treeLength = 0;

		for (int i = 0; i < n; i++)
		{
			treeLength += max(arrTreeList[i] - mid, (long long)0);
		}
		
		//cout << "st: " << st << " en: " << en << " mid: " << mid << " treelength: " << treeLength << endl;

		if (m > treeLength)		// 목표치보다 잘라낸 나무가 더 작으면 => 더 낮게 잘라야 함
		{
			en = mid -1;
		}

		else if (m <= treeLength)	// 잘라낸 나무가 목표치보다 크거나 같으면 => 좀더 높게 잘라야함
		{
			st = mid;
		}
	}

	cout << st;
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int temp;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arrTreeList.push_back(temp);
	}

	sort(arrTreeList.begin(), arrTreeList.end());
	Solve(); 

	return 0;
}

/*
* 하향 함수
* - 높이 중에서 
* =  길이의 upper bound 를 구해야 함 
*/