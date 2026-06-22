#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool Compare(const vector<int>& a, const vector<int>& b)
{
    return a[2] <= b[2];
}

int Find(vector<int>& parents, int curIdx)
{
    if (parents[curIdx] == curIdx) return curIdx;
    return parents[curIdx] = Find(parents, parents[curIdx]);
}

bool Union(vector<int>& parents, int a, int b)
{
    int rootA = Find(parents, a);
    int rootB = Find(parents, b);
    
    if (rootA != rootB)
    {
        parents[rootB] = rootA;
        return true;
    }
    
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> parents(100);
    
    sort(costs.begin(), costs.end(), Compare);
    
    for(int i = 0; i <parents.size(); i ++)
    {
        parents[i] = i;
    }
        
    for(auto cost: costs)
    {
        int a = cost[0];
        int b = cost[1];
        if(Union(parents, a, b) == true)
        {
            answer+= cost[2];
        }
    }
    return answer;
}

// 코스트 기준으로 정렬해서 작은 코스트부터 더하고 방문체크
// 방문 체크만해서는 모든 섬을 연결할 수없다  2개씩 페어로 연결되거나 하는경우가 있음.. unionfind 를 사용해야한다