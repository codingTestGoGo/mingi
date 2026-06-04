#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;


void Dijkstra(int start, vector<vector<int>>& edgeInform, vector<int>& dist, vector<bool>& isVisit)
{
    queue<int> q;
    
    q.push(1);
    dist[1] = 0;
    isVisit[1] = true;
    
    while(!q.empty())
    {
        int curNode = q.front();
        
        q.pop();
        
        for(auto next: edgeInform[curNode])
        {
            if (isVisit[next] == false)
            {
                isVisit[next] = true;
                if (dist[next] == -1)
                {
                    dist[next] = dist[curNode] + 1;
                }
                else
                {
                    dist[next] = min(dist[next], dist[curNode] + 1);
                }
                q.push(next);
            }
        }
            
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> edgeInform(20001);
    vector<bool> isVisit(20001, false);
    vector<int> dist(20001, -1);
    
    // 간선정리
    for(int i = 0; i < edge.size(); i ++)
    {
        int start = edge[i][0];
        int end = edge[i][1];
            
        edgeInform[start].push_back(end);
        edgeInform[end].push_back(start);
    }
    
    Dijkstra(1, edgeInform, dist, isVisit);
    for(int i = 1; i <=n ; i ++)
    {
        cout << dist[i] << " ";
    }
    
    sort(dist.begin(), dist.end(), greater<int>());
    int maxDist = dist[0];
    for(int i = 0 ; i <= dist.size(); i ++)
    {
        if (dist[i] != maxDist) break;
        answer++;
    }
    
    
    return answer;
}