#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr; 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int temp;
	int st, en, target, sum;
	int answer = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());


	for (int i = 0; i < n; i++)
	{
		target = arr[i];
		st = 0;
		en = n - 1;

		while (st < en)
		{
			sum = arr[st] + arr[en]; 
			
			if (st == i)
			{
				st += 1;
				continue;
			}
			else if (en == i)
			{
				en -= 1;
				continue;
			}

			if (sum == target)
			{
				answer++;
				break;
			}

			if (sum > target)
			{
				en -= 1;
			}

			else if (sum < target)
			{
				st += 1;
			}
		}
	}

	cout << answer;

	return 0;
}