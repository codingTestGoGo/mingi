#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string temp;
	cin >> temp;

	int vowel = 0;
	int yVowel = 0;

	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u')
		{
			vowel++;
			yVowel++;
		}
		else if (temp[i] == 'y')
		{
			yVowel++;
		}
	}


	cout << vowel << " " << yVowel;
	return 0;
}