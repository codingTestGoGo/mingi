#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int Find(vector<int>& parents, int curIdx)
{
    if(parents[curIdx] == curIdx)
    {
        return curIdx;
    }
    else
    {
        parents[curIdx] = Find(parents, parents[curIdx]);
        return parents[curIdx];
    }
}

bool Union(vector<int>& gates, vector<int>& summits, vector<int>& parents, vector<pair<int, int>>& candidate, int a, int b, int intensity)
{
    int rootA = Find(parents, a);
    int rootB = Find(parents, b);
    
    bool aIsGate = (find(gates.begin(), gates.end(), rootA) == gates.end()) ? false : true ; 
    bool bIsGate = (find(gates.begin(), gates.end(), rootB) == gates.end()) ? false : true ; 
    bool aIsSummits = (find(summits.begin(), summits.end(), rootA) == summits.end()) ? false : true ; 
    bool bIsSummits = (find(summits.begin(), summits.end(), rootB) == summits.end()) ? false : true ; 
    
    
    // 정답
    if( aIsGate&& bIsSummits )
    {
        candidate.push_back({rootB, intensity});
        return true;
    }
    else if(aIsSummits && bIsGate)
    {
        candidate.push_back({rootA, intensity});
        return true;
    }
    else if ((aIsGate && bIsGate) || (aIsSummits&& bIsSummits)) return false;
    else if(aIsGate || aIsSummits)
    {
        parents[rootB] = rootA;
        return false;
    }
    else if(bIsGate || bIsSummits)
    {
        parents[rootA] = rootB;
        return false;
    }
}

bool Compare(vector<int>& a, vector<int>& b)
{
    return a[2] < b[2];
}

bool candiCompare (const pair<int,int>& a, const pair<int, int>& b)
{
    if(a.second == b.second) return a.first< b.first;
    else return a.second< b.second;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    vector<int> parents(n+1,-1);
    vector<pair<int,int>> candidate;
    
    sort(paths.begin(), paths.end(), Compare);
    
    for(int i = 1; i <=n; i ++)
    {
        parents[i] = i;
    }
    
    for(auto path : paths)
    {
        int nodeA = path[0];
        int nodeB = path[1];
        int dist = path[2];
        
        bool temp = Union(gates, summits, parents, candidate, nodeA, nodeB, dist);
    }
    
    sort(candidate.begin(), candidate.end(), candiCompare);
    
    answer.push_back(candidate[0].first);
    answer.push_back(candidate[0].second);
    
    
    return answer;
}