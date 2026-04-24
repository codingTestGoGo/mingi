#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#define MAX 100000000

using namespace std;


vector<vector<pair<int, int>>> edges(201);
bool aVisit[201] = {0,};

vector<int> Dijkstra(int start)
{
    vector<int> dist(201);
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
    fill(dist.begin() , dist.end(), MAX);
    
    dist[start] = 0;
    pq.push({0, start});
    while(pq.empty() == false)
    {
        int curNode = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();
        
        if (curDist > dist[curNode]) continue;
        
        for( auto edge : edges[curNode])
        {
            int nextNode = edge.second;
            int nextDist = edge.first;
            
            if(curDist + nextDist >= dist[nextNode])
            {
                continue; 
                
            }
            
            pq.push({(nextDist + curDist), nextNode});
            dist[nextNode] = nextDist + curDist;
        }
    }
    
    return dist;
    
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    for(int i =0;i <fares.size(); i ++)
    {
        int start = fares[i][0];
        int end = fares[i][1];
        int cost = fares[i][2];
        edges[start].push_back({cost, end});
        edges[end].push_back({cost, start});
    }
    
        
    vector<int> aInfo = Dijkstra(a); 
    vector<int> bInfo = Dijkstra(b);
    vector<int> sInfo = Dijkstra(s);
    answer = sInfo[a] + sInfo[b];
    for(int i = 1; i <=n ; i++)
    {
        answer = min(answer, aInfo[i] + bInfo[i] + sInfo[i]);
    }
    
    return answer;
}

// n: 노드 갯수
// s: 출발지점
// a: a 도착지점
// b: b 도착지점
// 중간에 합승하는경우가 잇으까?
// a가 최단경로로 이동을 했다 .그러면 b가 이동할 대 a가 방문한 지점을 최단거리로 밟아야 한다면, 그 지점의 거리를 계산하지 않으면 되는것이 아닌가
// 다만 그러면 a가 그리는 최단경로를 전부 알아야할 필요가 있는데, 이를 어떻게 알지? => a의 최단경로만 방문체크할 방법이없다
// 0~ n까지의 모든 경유지를 지나서 s로가는 방법을 구해서 최소값을 구한다
