#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rootNode;
vector<int> nodesPrefix;

void PostOrder(int start, int end)
{
	if (start >= end) return;
	
	int rootNode = nodesPrefix[start];
	int rightIdx = start + 1;

	while (rightIdx < end && nodesPrefix[rightIdx] < rootNode)
	{
		rightIdx++;
	}

	PostOrder(start + 1, rightIdx);
	PostOrder(rightIdx, end);
	cout << rootNode << "\n";
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int temp;

	while (cin>>temp)
	{
		nodesPrefix.push_back(temp);
	}
	
	PostOrder(0, nodesPrefix.size());

	return 0;
}


/*
* * 전위로 트리 구성
*  => 전위 순서 만으로 트리를 만드는 것이 불가능함 어디까지가 depth인지 모르니
* * 후위로 출력하기
*  => 규칙을 찾아서 바로 후위로 출력해야만함
*/