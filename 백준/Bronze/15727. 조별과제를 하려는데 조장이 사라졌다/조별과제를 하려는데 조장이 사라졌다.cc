#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	if (t % 5 != 0)
	{
		cout << t / 5 + 1;
	}
	else
		cout << t / 5;
}