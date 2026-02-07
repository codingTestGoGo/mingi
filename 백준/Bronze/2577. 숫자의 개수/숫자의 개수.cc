#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int arr[10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, sum;
	string temp;

	cin >> a >> b >> c;
	sum = a * b * c;

	temp = to_string(sum);
	for (int i = 0; i < temp.length(); i++)
	{
		int index = temp[i] - 48;
		arr[index]++;
	}
	
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << "\n";
	}
	
	return 0;
}