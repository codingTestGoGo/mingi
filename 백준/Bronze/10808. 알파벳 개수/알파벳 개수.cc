#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int alphabetNum[26];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 
	string targetSentence;
	cin >> targetSentence;

	for (int i = 0; i < targetSentence.size(); i++)
	{
		char temp = targetSentence[i];
		alphabetNum[temp - 97]++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << alphabetNum[i] << " ";
	}

	return 0;
}