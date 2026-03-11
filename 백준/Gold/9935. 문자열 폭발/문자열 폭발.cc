#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

string targetString, explodeParam;
stack<char> exploded;
stack<int> overlapTemp;

void StringExplosion()
{
	for (int i = 0; i < explodeParam.length(); i++)
	{
		if (exploded.empty() == true) return;
		exploded.pop();
	}

	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> targetString >> explodeParam;
	int paramIndex = 0;

	for (int i = 0; i < targetString.length(); i++)
	{
		exploded.push(targetString[i]);
		
		// 연속해서 폭발문자가 발견되는경우
		if (exploded.top() == explodeParam[paramIndex])
		{
			paramIndex++;
			if (paramIndex == explodeParam.length())
			{
				StringExplosion();
				if (overlapTemp.empty() == false)
				{
					paramIndex = overlapTemp.top(); 
					overlapTemp.pop();
				}
				else
				{
					paramIndex = 0;
				}
			}
				
		}
		// 폭발문자안에 폭발문자가 잇는경우
		else if (exploded.top() == explodeParam[0])
		{
			overlapTemp.push(paramIndex);
			paramIndex = 1;
		}
		// 아예 처음으로 초기화
		else
		{
			paramIndex = 0;
			while (overlapTemp.empty() == false) overlapTemp.pop();
		}
	}

	if (exploded.empty() == true)
	{
		cout << "FRULA";
	}
	else
	{
		int stringLength = exploded.size();
		stack<char> temp;
		for (int i = 0; i < stringLength; i++)
		{
			temp.push(exploded.top());
			exploded.pop();
		}

		for (int i = 0; i < stringLength; i++)
		{
			cout << temp.top();
			temp.pop();
		}
	}

	return 0;
}



/*
* 터뜨린다음에 후처리 어떻게 할건가
* cccc4444 인경우  c4를 읽어서 터뜨렸을때 i는 뒤에서 3번째 4를 가리킨다.
*	=> 폭발이후에 stack의 탑과 param을 비교해서 index를 늘려주면된다.
* 폭발매개가 2글자보다 큰 경우는 어떻게하는가
* 
* 112ab 2ab 의경우 처음 폭발이후 스택에는 1이 남고,  i는 2를 가리킨다
* 12 12ab ab 는 어떻게처리?
*  => 
*/