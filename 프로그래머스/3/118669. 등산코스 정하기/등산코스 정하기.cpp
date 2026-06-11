#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

#define MAX 2000000000
using namespace std;

int finalIntensity = MAX;
int finalPeak = MAX;

void Dijkstra(vector<vector<pair<int, int>>>& edgeInform, vector<int>& gates, vector<int>& summits, int n, int start)
{
    int intensity = 0;
    priority_queue< pair<int,int> , vector<pair<int, int>>, greater<pair<int,int>>> pq;
    vector<bool> isVisit(n+1, false);
    vector<int> dist(n+1, MAX);
    dist[start] = 0;
    isVisit[start] = true;
    pq.push({0, start});
    
    while(!pq.empty())
    {
        // 현재 갈 수 있는 엣지 중에 가장 적은 것 부터 나올것.
        int curNode = pq.top().second;
        int curEdge = pq.top().first; 
        pq.pop();
        isVisit[curNode] = true;
        //cout << curNode << " ";

        if (curNode != start && find(summits.begin(), summits.end(), curNode) != summits.end())
            continue;
        
        intensity = max(intensity, curEdge);
        
        /*
        cout << intensity <<endl;
        for(int i = 1; i <=n; i++)
        {
            if (dist[i] == MAX) cout <<-1 <<" ";
            else
                cout<<dist[i] << " ";
        }
        cout <<endl;
        */
        if (intensity > finalIntensity) break;
        
        // 봉우리에서 최소엣지 고르면서 내려오다가 입구를 찾앗다면
        if(find(gates.begin(), gates.end(), curNode) != gates.end())
        {
            if(intensity == finalIntensity)
            {
                finalPeak = min(finalPeak, start);
                break;
            }
            else
            {
                finalIntensity = intensity;
                finalPeak = start;
                break;
            }
        }
        
        for(auto edge: edgeInform[curNode])
        {
            int nextNode = edge.second;
            int nextDist = edge.first;
            
            if(isVisit[nextNode] == false )
            {
                //cout<< "next: " <<nextNode << "nDist: " << nextDist <<endl;
                pq.push({nextDist, nextNode});
                //dist[nextNode] = dist[curNode] + nextDist;
            }
        }
    }
    
    
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    vector<vector<pair<int, int>>> edgeInform(n+1);
    for(auto path: paths)
    {
        int start = path[0];
        int end = path[1];
        int dist = path[2];
        
        edgeInform[start].push_back({dist, end});
        edgeInform[end].push_back({dist, start});
    }
    
    for(auto peak: summits)
    {
        Dijkstra(edgeInform, gates, summits, n, peak);
    }
    
    answer.push_back(finalPeak); 
    answer.push_back(finalIntensity);
    return answer;
}

/*
도착 지점부터 시작해서 시작지점까지의 최소 길이를 찾는다.
도착 지점은 번호가 낮은 순서대로 실행한다.
priorityqueue를 이용해서 현재 접근할 수 잇는 노드 중에가장 값이 적은 노드만 찾는다.
노드를 타고 이동할 때마다 intensity를 갱신한다. 
출발지점에 도착하면 끝내고 다음 노드 번호 를 시작점으로 탐색시작 
이때 갱신한 intensity보다 큰 노드는 무시한다. 

*/