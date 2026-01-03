#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;
vector<int> arr;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0); 

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		int maxScore = 0;
		int winnerIndex;
		int totalVote = 0;

		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;

			totalVote += temp;
			if (maxScore < temp)
			{
				maxScore = temp;
				winnerIndex = j;
			}
			arr.push_back(temp);
		}

		sort(arr.begin(), arr.end());
		if (arr[arr.size() - 1] == arr[arr.size() -2])
		{
			cout << "no winner" << "\n"; 
		}

		else if (maxScore > totalVote / 2)
		{
			cout << "majority winner " << winnerIndex + 1 << "\n";
		}

		else if (maxScore <= totalVote / 2)
		{
			cout << "minority winner " << winnerIndex + 1 << "\n";
		}

		arr.clear(); 
	}

	return 0;
}