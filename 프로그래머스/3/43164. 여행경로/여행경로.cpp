#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool DFS(vector<vector<string>>& tickets , vector<bool>& isVisit, vector<string>& route, string curAirport, int depth )
{
    route.push_back(curAirport);
    
    if(depth == tickets.size()) return true;
    
    for(int i = 0; i <tickets.size(); i ++)
    {
        if (tickets[i][0] == curAirport && isVisit[i] == false)
        {
            isVisit[i] = true;
            if (DFS(tickets, isVisit, route, tickets[i][1], depth+1) == true)
                return true;
            isVisit[i] = false;
            route.pop_back();
        }
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> isVisit(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    vector<string> route;
    
    DFS(tickets, isVisit, route, "ICN", 0);
     
    return route;
}

