#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n;
    int answer = 1;
    cin >> n;

    if (n == 0)
    {
        cout << 1;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        answer *= i;
    }

    cout << answer;
    return 0;
}