#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <iostream>

using namespace std;

// 번호, 시작, 소요시간
struct Compare
{
   bool operator()(tuple<int, int, int>& a, tuple<int, int, int>& b) const
   {
       int aWorkTime = get<2>(a);
       int bWorkTime = get<2>(b);
       int aStart = get<1>(a);
       int bStart = get<1>(b);
       int aIdx = get<0>(a);
       int bIdx = get<0>(b);
       
       if (aWorkTime == bWorkTime && aStart == bStart)
       {
           return aIdx > bIdx;
       }
       else if ( aWorkTime == bWorkTime)
       {
           return aStart > bStart;
       }
       else
           return aWorkTime > bWorkTime;
   }
}; 


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n = jobs.size();
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> pq;
    vector<vector<int>> startTimes(2001);
    
    for(int i = 0;i <jobs.size(); i++)
    {
        int idx = i;
        int start = jobs[i][0];
        startTimes[start].push_back(idx);
    }
    
    int timer = 0;
    int startedTime = -1;
    int lastTime = -1;
    int curWork = -1;
    int completedCnt = 0;
    
    while(1)
    {
        // 타임마다 시작요청 작업이 있으면 넣는다.
        /*
        for(int i = 0; i <startTimes[timer].size(); i++)
        {
            int idx = startTimes[timer][i];
            int start = timer;
            int workingTime = jobs[idx][1];
            pq.push({idx, start, workingTime});
        }
        */
        for(int i = 0; i <jobs.size(); i++)
        {
            if(jobs[i][0] == timer) 
            {
                int idx = i;
                int start = timer;
                int workingTime = jobs[i][1];
                pq.push({idx, start, workingTime});
            }
        }
        
        // 하던 작업이 끝낫으면
        if (lastTime == 0)
        {
            curWork = -1;
            answer += timer - startedTime;
            completedCnt++;
            //cout<< "endTime: " <<timer << endl;
            if( completedCnt == n) break;
        }
        
        // 하던 작업이 없는 경우 
        if (curWork == -1)
        {
            if(!pq.empty())
            {
                curWork = get<0>(pq.top());
                startedTime = get<1>(pq.top());
                lastTime = get<2>(pq.top());
                pq.pop();
            }

            //cout <<"curWork: " << curWork;
            //cout <<" startedTime: " << startedTime<< endl;
        }
        
        lastTime--;
        timer++;    
    }
    cout<< answer << endl;
    answer /= n;
    return answer;
}
/*
// 큐에 들어간 순간부터 작업이 완료되는 시점까지가 반환시간
// 해당 반환 시간의 평균값을 구하는 문제
// 작업중에도 대기 큐에 작업을 추가하는건 괜찮다.
// 작업 소요시간이 짧은거 먼저. / 요청 시각이 빠른것. 작업의 번호가 작은것.
// 작업 번호는 jobs 벡터의인덱스
// 시작 순회와 완료 순회를 어떻게 할 것인가?
    
*/