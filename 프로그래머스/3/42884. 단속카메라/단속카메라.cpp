#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(vector<int>& a , vector<int>& b)
{
    if (a[0] == b[0]) return a[1] < b[1];
    else return a[0] <b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<pair<int, int>> criticalSection;
    
    sort(routes.begin(), routes.end(), Compare);
    
    for(auto route : routes)
    {
        int routeStart = route[0];
        int routeEnd = route[1];
        bool newSectionNeed = true;
        
        // 교차검사
        for(int i = 0; i < criticalSection.size(); i++)
        {
            int secStart = criticalSection[i].first;
            int secEnd = criticalSection[i].second;
            
            // 겹치지 않을경우
            if(routeEnd < secStart || routeStart > secEnd)
            {
                continue;
            }
            else
            {
                criticalSection[i].first = max(routeStart, secStart);
                criticalSection[i].second = min(routeEnd, secEnd);
                newSectionNeed = false;
                break;
            }
        }
        
        if(newSectionNeed == true)
        {
            criticalSection.push_back({routeStart, routeEnd});
        }
        
    }
    
    answer = criticalSection.size();
    
    
    return answer;
}