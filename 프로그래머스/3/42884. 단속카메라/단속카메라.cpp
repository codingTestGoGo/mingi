#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(vector<int>& a, vector<int>& b) 
{
    return a[1] <= b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int camera = -30001;
    sort(routes.begin(), routes.end(), Compare);
    
    for(auto route : routes)
    {
        if(route[0] > camera)
        {
            answer++;
            camera = route[1];
        }
    }
    return answer;
}