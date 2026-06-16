#include <string>
#include <vector>

using namespace std;

long long GetMaxCheckCnt(long long totalTime, vector<int>& times)
{
    long long checkable = 0;
    for(auto checkTime : times)
    {
        checkable += totalTime / checkTime;
    }
    return checkable;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long lo = 1;
    long long hi = 1000000000000000000;
    
    while( lo < hi)
    {
        long long mid = (lo + hi) /2;
        if(GetMaxCheckCnt(mid, times) >= n)
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    answer = lo;
    
    return answer;
}

