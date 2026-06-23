#include <string>
#include <vector>

using namespace std;
int answer = 0;


void DFS(vector<vector<int>>& childrens, vector<int>& candidates, vector<int>& info, int sheep, int wolf)
{
    if(wolf >= sheep) return;
    answer = max(answer, sheep);
    
    // 후보자 순회
    // 칠드런 벡터 복사 및 선택한 후보의 자식 추가
    // 후보자 info 판단 sheep, wolf 정해서 추가하고 dfs 호출

    for(int i = 0; i < candidates.size() ; i++)
    {
        int nextChild = candidates[i];
        vector<int> next = candidates;
        next.erase(next.begin() + i);
        
        for(auto child: childrens[nextChild])
        {
            next.push_back(child);
        }
        
        if (info[nextChild] == 0) 
            DFS(childrens, next, info, sheep+1, wolf);
        else
            DFS(childrens, next, info, sheep, wolf + 1);
    }
    
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();
    vector<vector<int>> childrens(n);
    vector<int> candidates;
    
    for(auto edge : edges)
    {
        int parent = edge[0];
        int child = edge[1];
        childrens[parent].push_back(child);
    }
    
    for(auto child : childrens[0] )
    {
        candidates.push_back(child);
    }
    
    DFS(childrens, candidates, info, 1, 0);
    
    return answer;
}