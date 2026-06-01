#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int answer = -1;

void DFS(vector<vector<int>>& dungeons, vector<bool>& isVisit, vector<int>& curRoute, int fatigue)
{
    
    if (curRoute.empty() == false)
    {
        int curSize = curRoute.size();
        answer = max(answer, curSize);
    }
    
    for(int i = 0 ; i <dungeons.size(); i++)
    {
        if (isVisit[i] == false && fatigue >= dungeons[i][0])
        {
            isVisit[i] = true;
            curRoute.push_back(i);    
            DFS(dungeons, isVisit, curRoute, fatigue - dungeons[i][1]);
            isVisit[i] = false;
            curRoute.pop_back();
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> isVisit(dungeons.size(), false);
    vector<int> curRoute;
    DFS(dungeons, isVisit, curRoute, k);
    
    return answer;
}

// 항상 최소 필요피로가 소모 피로보다 크같
// 던전의 크기는 최대 5000  dfs?
