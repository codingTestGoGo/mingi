#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void Dijkstra(vector<vector<pair<int,int>>>& edge, vector<int>& dist, int N, int K)
{
    priority_queue<pair<int,int>, vector<pair<int, int>>, less<pair<int,int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty())
    {
        int curNode = pq.top().second;
        pq.pop();
        
        for(auto next : edge[curNode])
        {
            int nextNode = next.second;
            int nextDist = next.first;
            
            if (dist[nextNode] <= (dist[curNode] + nextDist)) continue;
            dist[nextNode] = dist[curNode] + nextDist;
            pq.push(next);
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    //vector<priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>> pq(N +1);
    vector<vector<pair<int,int>>> edgeInform(N+1);
    vector<int> dist(N+1, 1000000);
    
    for(int i = 0; i < road.size(); i ++)
    {
        int start = road[i][0];
        int end = road[i][1];
        int cost = road[i][2];
        
        edgeInform[start].push_back({cost, end});
        edgeInform[end].push_back({cost, start});
    }
    
    Dijkstra(edgeInform, dist, N, K);
    
    for(int i = 0; i < dist.size(); i ++) 
    {
        if(dist[i] <= K) answer++;
    }
    
        
    return answer;
}