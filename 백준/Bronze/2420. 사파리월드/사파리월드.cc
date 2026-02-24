#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    long long a, b, answer; 
    cin >>a >> b;
    // 부호가 같음
    if( ((a < 0) && (b<0)) || ((a>0) && (b>0)))
    {
        answer = abs(a - b);
    }
    // 부호가 다름
    else
    {
        answer = abs(a) + abs(b);
    }
    
    cout << answer;
    return 0;
}