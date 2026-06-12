#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;
};

void ExecuteCmds(vector<Node>& table, vector<string>& cmds, vector<bool>& activated, int k )
{
    Node* curNode = &table[k];
    stack<int> deletedElements;
    
    for(auto cmd : cmds)
    {
        if ( cmd[0] == 'U')
        {
            int value = stoi(cmd.substr(1));
            Node* nextNode = curNode; 
            while(1)
            {
                if (value == 0) break;
                if (nextNode->prev != nullptr)
                    nextNode = nextNode->prev;
                value--;
            }
            curNode = nextNode;
        }
        else if ( cmd[0] == 'D')
        {
            int value = stoi(cmd.substr(1));
            Node* nextNode = curNode;
            while(1)
            {
                if (value == 0) break;
                if ( nextNode->next != nullptr)
                    nextNode = nextNode->next;
                value--;
            }
            curNode = nextNode;
        }
        else if ( cmd[0] == 'C')
        {
            deletedElements.push(curNode->value);
            activated[curNode->value] = false;
            if ( curNode -> prev)
            {
                curNode->prev->next = curNode->next;
            }
            if (curNode -> next)
            {
                curNode->next->prev = curNode->prev;
            }
            
            
            if (curNode -> next)
            {
                curNode = curNode->next;
            }
            else
            {
                curNode = curNode->prev;
            }
        }
        else if ( cmd[0] == 'Z')
        {
            int targetIdx = deletedElements.top();
            Node* targetNode = &table[targetIdx];
            activated[targetIdx] = true;
            deletedElements.pop();
            if( targetNode->prev)
            {
                targetNode->prev->next = targetNode;
            }
            if ( targetNode -> next)
            {
                targetNode->next->prev = targetNode;
            }
            
        }
        else continue;
    }
    
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<Node> table(n);
    vector<bool> activated(n, true);
    for(int i = 0; i <n; i++)
    {
        if( i == 0)
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
        table[i].value = i;
    }
    
    ExecuteCmds(table, cmd, activated, k);
    
    for(int i = 0; i < n; i ++)
    {
        if(activated[i] == true) answer+= "O";
        else answer += "X";
    }
    
    return answer;
}