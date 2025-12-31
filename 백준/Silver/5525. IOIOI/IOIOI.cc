#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
string p = "I";
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> s;

	vector<char> pVector;

	pVector.push_back('I');
	for (int i = 0; i < n; i++)
	{
		pVector.push_back('O');
		pVector.push_back('I');
	}

	p.assign(pVector.begin(), pVector.end());

	int answer = 0;

	for (int i = 0; i < m-2; i++)
	{
		if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I')
		{
			int count = 0;

			while ( s[i +1] =='O' && s[i+2] == 'I')
			{
				count ++;

				if (count == n)
				{
					answer++;
					count--;
				}

				i += 2;
			}
		}
	}
	
	cout << answer;
	return 0;
}