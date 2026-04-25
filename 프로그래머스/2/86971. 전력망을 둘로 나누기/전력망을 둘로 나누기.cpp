#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int>> edges(101);
bool visitCheck[101];

int BFS(int ignoreA, int ignoreB)
{
    fill(visitCheck, visitCheck + 101, false);
    queue<int> q;
    q.push(ignoreA);
    visitCheck[ignoreA] = true;
    int nodeCnt =1 ;
    
    while(q.empty() == false)
    {
        int curNode = q.front();
        q.pop();
        
        for(auto nextNode :edges[curNode])
        {
            if( (curNode == ignoreA && nextNode == ignoreB) ||
                (curNode == ignoreB && nextNode == ignoreA))
            {
                continue;
            }
            
            else if (visitCheck[nextNode] == true) continue;
            
            q.push(nextNode);
            visitCheck[nextNode] = true;
            nodeCnt++;
        }
    }
    
    return nodeCnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    
    for (int i =0; i<wires.size(); i ++)
    {
        int start = wires[i][0];
        int end = wires[i][1];
        
        edges[start].push_back(end);
        edges[end].push_back(start);
    }
    
    
    for(int i = 0; i <wires.size() ; i ++)
    {
        int a = wires[i][0];
        int b = wires[i][1];
        
        int partA = BFS(a, b);
        int partB = n- partA;
        
        answer = min ( answer, abs(partA - partB));
        
    }
    
    
    
    return answer;
}