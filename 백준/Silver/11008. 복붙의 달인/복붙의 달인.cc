#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int t;
string p, s;

void CompareStrings()
{
	int typingTime = 0;
	int curIndex;
	int wordLength = s.length();
	int keywordLength = p.length();

	for (int i = 0; i < wordLength; i++)
	{
		if (s[i] == p[0] && i + keywordLength <= wordLength)
		{
			for (int j = 0; j < keywordLength; j++)
			{
				if (j == keywordLength - 1 && s[i + j] == p[j])
				{
					typingTime++;
					i += keywordLength-1;
					break;
				}

				else if (s[i + j] == p[j]) 
				{
					continue;
				}

				else
				{
					typingTime++;
					break;
				}
			}
		}

		else
		{
			typingTime++; 
		}
	}

	cout << typingTime << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> s >> p;
		CompareStrings();
	}

	return 0;
}