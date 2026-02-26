#include <iostream>
#include <string>
using namespace std;

int main()
{
    string temp; 
    cin >> temp;
    
    int cnt = 0;
    for(int i =0; i<temp.length(); i++)
    {
        if(cnt == 10)
        {
            cout << "\n";
            cnt = 0;
        }
        cout <<temp[i];
        cnt++;
    }
    
    return 0;
}