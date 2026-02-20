#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int facto[11];

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);

	int t, n;
	cin >> t;

	facto[0] = 1;
	facto[1] = 1;
	facto[2] = 2;

	for (int i = 3; i < 11; i++)
	{
		facto[i] = facto[i - 1] * i;
	}

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		string temp = to_string(facto[n]);
		int index = temp.length() -1;
		cout << temp[index]<<"\n";
	}
	return 0;
}