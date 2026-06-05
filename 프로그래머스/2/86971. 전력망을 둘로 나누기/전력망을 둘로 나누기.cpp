#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;


void BFS(vector<vector<int>>& edgeInform, vector<bool>& isVisit, int cutA, int cutB)
{
    queue<int> q;
    q.push(1);
    isVisit[1] = true;
    
    while(!q.empty())
    {
        int curNode = q.front();
        q.pop();
        
        for(auto next: edgeInform[curNode])
        {
            if (curNode == cutA && next == cutB) continue;
            if (curNode == cutB && next == cutA) continue;
            
            if(isVisit[next] == false)
            {
                isVisit[next] = true;
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    vector<vector<int>> edgeInform (n+1);
    vector<bool> isVisit(n+1, false);
    
    for(int i = 0; i < wires.size(); i++)
    {
        int start = wires[i][0];
        int end = wires[i][1];
        edgeInform[start].push_back(end);
        edgeInform[end].push_back(start);
    }
    
    for(auto wire : wires)
    {
        int groupCnt = 0;
        BFS(edgeInform, isVisit, wire[0], wire[1]);
        for(int i = 1; i <= n; i ++)
        {
            if (isVisit[i] == true) groupCnt++;
        }
        answer = min (answer, abs((n-groupCnt) - groupCnt));
        fill(isVisit.begin(), isVisit.end(), false);
    }
    
    return answer;
}