#include <string>
#include <vector>
#include <algorithm> 
#include <iostream>

using namespace std;

bool CanMinDistCheck(vector<int>& rocks, int n, int minDist, int distance)
{
    int prev = 0;
    int removeCnt = 0;
    
    for(int i =0; i <rocks.size(); i++)
    {
        // 거리가 부족해서 바위를 지워야 함
        if (rocks[i] - prev < minDist)
        {
            removeCnt++;
        }
        // 거리가 충분히 커서 바위를 제거할 필요가 없음
        else if(rocks[i] - prev >= minDist)
        {
            prev = rocks[i];
        }
    }
    
    if(distance - prev < minDist)
        removeCnt++;
    
    return removeCnt <= n;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    int lo = 0;
    int hi = distance;
    int mid;
    
    sort(rocks.begin(), rocks.end());
    
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        //cout << mid<< endl;    
        // 최소달성가능 => 줄여야함
        if(CanMinDistCheck(rocks, n, mid, distance))
        {
            lo = mid + 1;
            answer = mid;            
        }
        else
            hi = mid - 1;
    }
    
    return answer;
}