#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> parenthesis;

    for(int i =0; i <s.length(); i++)
    {
        if( parenthesis.empty())
        {
            parenthesis.push(s[i]);
            continue;            
        }
        char stackTop = parenthesis.top();
        
        if(stackTop == '(' && s[i] == ')')
        { 
            parenthesis.pop();
            continue;
        }
        parenthesis.push(s[i]);
    }
    
    if (parenthesis.empty())
    {
        answer = true;
    }
    else{
        answer = false;
    }

    return answer;
}