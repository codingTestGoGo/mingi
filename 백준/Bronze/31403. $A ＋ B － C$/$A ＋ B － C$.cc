#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	string temp = "";
	cin >> a >> b >> c;
	cout << a + b - c << "\n";

	temp += to_string(a);
	temp += to_string(b);
	int ab = stoi(temp);
	cout << ab - c;

	return 0;
}
