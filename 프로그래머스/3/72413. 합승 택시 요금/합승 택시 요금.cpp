#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 100000000
using namespace std;

void Dijkstra(vector<vector<pair<int,int>>>& edgeInform, vector<int>& dist, int start)
{
    priority_queue<pair<int, int>, vector<pair<int,int>>, less<pair<int,int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
    
    while(!pq.empty())
    {
        int curNode = pq.top().second;
        pq.pop();
        
        for(auto next : edgeInform[curNode])
        {
            int nextNode = next.second;
            int nextDist = next.first;
            
            if (dist[nextNode] <= dist[curNode] + nextDist) continue;
            dist[nextNode] = dist[curNode] + nextDist;
            pq.push(next);
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = MAX;
    
    vector<vector<pair<int, int>>> edgeInform(n+1);
    vector<int> distS(n+1, MAX);
    vector<int> distA(n+1, MAX);
    vector<int> distB(n+1, MAX);
    
    for(int i = 0; i <fares.size(); i ++)
    {
        int start = fares[i][0];
        int end = fares[i][1];
        int cost = fares[i][2];
        
        edgeInform[start].push_back({cost, end}); 
        edgeInform[end].push_back({cost, start});
    }
    
    Dijkstra(edgeInform, distS, s);
    Dijkstra(edgeInform, distA, a);
    Dijkstra(edgeInform, distB, b);
    
    for(int i = 1; i <= n; i++)
    { 
        answer = min(distS[i] + distA[i] + distB[i], answer);
    }
    
    
    return answer;
}