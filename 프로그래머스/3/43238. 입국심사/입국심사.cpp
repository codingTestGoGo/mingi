#include <string>
#include <vector>
#include <iostream>

#define MAX 1000000000000000000
using namespace std;

long long findN(long long curTime, vector<int>& times) 
{
    long long result = 0; 
    for(auto time: times)
    {
        result += curTime / (long long)time;
    }
    return result;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long lo = 0; 
    long long hi = MAX;
    long long mid;
    long long curN;
    
    while(lo < hi)
    {
        mid = (lo + hi) / 2;
        curN = findN(mid, times);
        //시간이 충분
        if( curN >= n)
        {
            hi = mid;
        }
        // 시간이 부족
        else if (curN< n)
        {
            lo = mid + 1;
        }
    }
    
    answer = lo;
    return answer;
}
// 주어진 시간 / 각 타임의 합이 time 안에 검사할 수잇는 인간의 수Tn인데,
// Tn >= n 이 되는 구간안에서 time의 최소값을 구하는 파라매트릭 서치
/*
lower_bound를 쓰기 위해서는 어떤 방식이 좋을까
n의 lowerbound를 검색해서 6을 넣엇을때 time이 나와야한다
*/