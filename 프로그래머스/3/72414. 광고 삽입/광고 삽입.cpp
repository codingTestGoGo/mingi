#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int StringToTime(string timeLog)
{
    int time = 0;
    int hour =stoi(timeLog.substr(0, 2));
    int min = stoi(timeLog.substr(3, 5));
    int sec = stoi(timeLog.substr(6, 8));
    
    time += hour*3600 + min * 60 + sec;
    
    return time;
}

string IntToString(int time)
{
    string timeStemp = "";
    int hour = time/3600;
    int min = time%3600 /60;
    int sec = time%3600%60;
    
    /*
    cout << hour<< endl;
    cout << min << endl;
    cout << sec << endl;
    */
    
    if(hour < 10) timeStemp += "0";
    timeStemp += to_string(hour);
    timeStemp += ":";
    if(min < 10) timeStemp += "0";
    timeStemp += to_string(min);
    timeStemp += ":";
    if(sec < 10) timeStemp += "0";
    timeStemp += to_string(sec);
    
    
    return timeStemp;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    int playTime = StringToTime(play_time);
    int adLength = StringToTime(adv_time);
    vector<int> accumulated(playTime+2, 0);
    vector<int> timeBoard(playTime +1, 0);
    
    // 누적합 체크
    for(auto log : logs)
    {
        string startLog = log.substr(0, 8);
        string endLog = log.substr(9);
        //cout << startLog <<endl << endLog <<endl;
        
        int startTime = StringToTime(startLog);
        int endTime = StringToTime(endLog);
        
        accumulated[startTime] += 1;
        accumulated[endTime] += -1;
    }
    
    timeBoard[0] = accumulated[0];
    // 누적합 적용
    for(int i = 1; i <timeBoard.size(); i ++)
    {
        timeBoard[i] = timeBoard[i-1] + accumulated[i];
    }
    
    // 투포인터로 구간탐색
    int left = 0;
    int right = 0;
    long long bestBroadCast= 0;
    long long curBroadCast = 0;
    int bestLeft = 0;
    
    for(int i = 0; i < timeBoard.size(); i++)
    {
        //right를 올리기전에 검사해야함
        curBroadCast += timeBoard[right];
        if (right-left +1 == adLength && curBroadCast > bestBroadCast)
        {
            //cout << "left: " << left <<endl;
            //cout << "right: " << right << endl;
            //cout << "curbroad / bestBroad " << curBroadCast << " " << bestBroadCast  <<endl;
            bestBroadCast = curBroadCast;
            bestLeft = left;
        }
        right++;
        
        while( right-left +1 > adLength)
        {
            curBroadCast -= timeBoard[left];
            left++;
            
            if (right-left +1 == adLength && curBroadCast > bestBroadCast)
            {
                //cout << "left: " << left <<endl;
                //cout << "right: " << right << endl;
                //cout << "curbroad / bestBroad " << curBroadCast << " " << bestBroadCast  <<endl;
                bestBroadCast = curBroadCast;
                bestLeft = left;
            }
            
        }
        

    }
    answer = IntToString(bestLeft);
    
    return answer;
}

/*
3차원 벡터에 이모스법으로 1차원처럼 누적합을 기록
 => 시간을 전부 초로 환산해서 1차원으로 다룰까? 
투포인터로 광고시간만큼 구간을 늘리면서 한번만 순회..
*/