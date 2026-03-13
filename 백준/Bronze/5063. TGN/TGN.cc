#include <iostream>

using namespace std;

int main()
{
    int a, b, c, n;
    cin >> n;
    
    for (int i = 0; i < n ; i++)
    {
        cin >>a >> b>> c;
        if ( a< (b-c)) cout << "advertise\n";
        else if( a == (b-c)) cout << "does not matter\n";
        else if( a > (b-c)) cout << "do not advertise\n";
    }
    return 0;
}