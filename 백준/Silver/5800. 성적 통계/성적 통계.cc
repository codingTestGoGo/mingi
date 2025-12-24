#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> scoresArr;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int studentNum;
		int score;
		int largestGap = 0;

		cin >> studentNum;

		for (int j = 0; j < studentNum; j++)
		{
			cin >> score;
			scoresArr.push_back(score);
		}

		sort(scoresArr.begin(), scoresArr.end());

		for (int i = 0; i < scoresArr.size() -1; i++)
		{
			largestGap = max(largestGap, scoresArr[i + 1] - scoresArr[i]);
		}

		cout << "Class " << i << "\n";
		cout << "Max " << scoresArr[studentNum - 1] << ", ";
		cout << "Min " << scoresArr[0] << ", ";
		cout << "Largest gap " << largestGap << "\n";

		scoresArr.clear();
	}

	return 0;
}