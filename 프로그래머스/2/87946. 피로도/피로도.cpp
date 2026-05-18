#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

bool visitCheck[8] = {false,};
int finalCnt =0;
int minFatigue = 1001;
/*
재귀를 멈추는 시기가 언제인가
피로가 0이하일때?
*/
void FindRoute(int fatigue, int curIdx, int visitCnt, vector<vector<int>>& dungeons)
{
    if ( fatigue < minFatigue) 
    {
        return;
    }
    
    for(int i = 0; i < dungeons.size() ; i++)
    {
        if (visitCheck[i] == true) continue;
        if (fatigue >= dungeons[i][0])
        {
            visitCnt++;
            finalCnt = max(finalCnt, visitCnt);
            visitCheck[i] = true;
            fatigue -= dungeons[i][1];
            
            //cout << "idx : " << i << " " << "visitCnt: " << visitCnt << endl;
            FindRoute(fatigue, i, visitCnt, dungeons);
            visitCheck[i] = false;
            fatigue += dungeons[i][1];
            visitCnt--;
            
        }
       
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    for(int i =0; i<dungeons.size(); i ++)
    {
        minFatigue = min(dungeons[i][0], minFatigue);
    }
    
    FindRoute(k, 0, 0, dungeons);
    
    answer = finalCnt;
    return answer;
}