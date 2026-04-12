#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX 10000001

using namespace std;
int n;

vector<int> primeNumber;
bool isPrime[MAX];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(isPrime, true, MAX);
	cin >> n;
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < MAX; i++)
	{
		if (isPrime[i] == true) {
			primeNumber.push_back(i);
			int multiplier = 2;
			while (1)
			{
				if (i * multiplier >= MAX) break;
				isPrime[i * multiplier] = false;
				multiplier++;
			}
		}
	}
	
	for (int prime : primeNumber)
	{
		while (1)
		{
			if (n % prime != 0) break;
			cout << prime << "\n";
			n /= prime;
		}
	}
	
	return 0;
}