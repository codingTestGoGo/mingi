#include <iostream>

using namespace std;

int main()
{
    string temp;
    cin >>temp;
    
    if(temp == "A+") cout<<"4.3";
    
    else if(temp == "A0") cout<<"4.0";
    else if(temp == "A-") cout<<"3.7";
    else if(temp == "B+") cout<<"3.3";
    else if(temp == "B0") cout<<"3.0";
    else if(temp == "B-") cout<<"2.7";
    else if(temp == "C+") cout<<"2.3";
    else if(temp == "C0") cout<<"2.0";
    else if(temp == "C-") cout<<"1.7";
    else if(temp == "D+") cout<<"1.3";
    else if(temp == "D0") cout<<"1.0";
    else if(temp == "D-") cout<<"0.7";
    else if(temp == "F") cout<<"0.0";
    
    return 0;
}