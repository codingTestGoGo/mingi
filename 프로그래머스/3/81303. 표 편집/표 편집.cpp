#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

struct Node
{
    int index;
    Node* next;
    Node* prev;
};

void ExecuteCmd(vector<Node>& table, vector<string>& cmds, vector<bool>& canUse, int curPos)
{
    stack<int> deletedElements;
    for(auto cmd : cmds) 
    {
        if(cmd[0] == 'U')
        {
            int moveValue = stoi(cmd.substr(2));
            Node* it = &table[curPos];
            while(moveValue > 0)
            {
                if(it->prev == nullptr) break;
                it = it->prev;
                moveValue --;
            }
            curPos = it->index;
        }
        else if (cmd[0] == 'D')
        {
            int moveValue = stoi(cmd.substr(2));
            Node* it = &table[curPos];
            while(moveValue > 0)
            {
                if(it->next == nullptr) break;
                it = it->next;
                moveValue --;
            }
            curPos = it->index;
        }
        else if (cmd[0] == 'C')
        {
            deletedElements.push(curPos);
            canUse[curPos] = false;
            if (table[curPos].prev)
            {
                table[curPos].prev->next = table[curPos].next;
            }
            if (table[curPos].next)
            {
                table[curPos].next->prev = table[curPos].prev;
            }
            
            if(table[curPos].next)
            {
                curPos = table[curPos].next->index;
            }
            else
            {
                curPos = table[curPos].prev->index;
            }
        }
        else if (cmd[0] == 'Z')
        {
            int recoverPos =deletedElements.top();
            deletedElements.pop();
            canUse[recoverPos] = true;
            if (table[recoverPos].next) 
            {
                table[recoverPos].next->prev = &table[recoverPos];
            }
            if (table[recoverPos].prev)
            {
                table[recoverPos].prev->next = &table[recoverPos];
            }
            
        }
        else
            continue;
    }
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<Node> table(n);
    vector<bool> canUse(n, true);
    
    for(int i = 0; i <n; i ++)
    {
        table[i].index = i;
        
        if(i == 0)
        {
            table[i].prev = nullptr;
            table[i].next = &table[i+1];
        }
        else if ( i == n-1)
        {
            table[i].prev = &table[i-1];
            table[i].next = nullptr;
        }
        else
        {
            table[i].prev = &table[i-1];
            table[i].next = &table[i+1];
        }
        
        //cout << table[i].index << " ";
    }
    ExecuteCmd(table, cmd, canUse, k);
    
    for(int i = 0; i < n; i++ )
    {
        if(canUse[i]) 
        {
            answer += "O";
        }
        else
        {
            answer+= "X";
        }
    }
    
    return answer;
}