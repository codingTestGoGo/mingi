#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map> 
#include <deque>

using namespace std;

deque<string> curAirlines;
vector<vector<string>> answerCandidate;

// 사이즈는 중복이 나올 수도 잇어서.. 그만 둬야할 시점을 어떻게 정할 수 있지?
// 아 어차피 모든 공항이 적혀있고, 모든티켓을 써야해 그러면 isVisit을 선형탐색할수밖에 없다고?미친건가
void DFS(vector<vector<string>>& tickets, vector<bool>& isVisit, string target)
{
    curAirlines.push_back(target);
    
    // isVisit이 전부 true라면?
    for(int i = 0; i<isVisit.size(); i ++)
    {
        if(isVisit[i] == false) break;      // 하나라도 false라면 다음 공항 탐색 하자
        
        // 전부 true라면
        else if (i == (isVisit.size()-1))
        {
            vector<string> temp;
            for(auto airline : curAirlines)
            {
                temp.push_back(airline);
            }
            answerCandidate.push_back(temp); 
        }
    }
    
    for(int i = 0; i < tickets.size(); i++)
    {
        if(tickets[i][0] == target && isVisit[i] == false)
        {
            isVisit[i] = true;
            DFS(tickets, isVisit, tickets[i][1]);
            isVisit[i] = false;
            curAirlines.pop_back();
        }
    }
}

bool CurAnswerIsFast(const vector<string>& a, const vector<string>& b) 
{
    if( a.size() != b.size()) return a.size() < b.size();
    
    for(int i = 0; i < a.size(); i++)
    {
        if( a[i] == b[i]) continue;
        else return a[i] <b[i];
    }
    
    return true;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> isVisit(tickets.size(), false);
     
    DFS(tickets, isVisit, "ICN");
    int answerIdx = 0;
    
    
    for(int i = 0; i < answerCandidate.size(); i++)
    {
        if(CurAnswerIsFast(answerCandidate[answerIdx], answerCandidate[i]))
        {
            continue;
        }
        answerIdx = i;
    }
    
    /*
    for(auto airport : answerCandidate[answerIdx])
    {
        answer.push_back(airport);
    }
    */
        
    //return answer;
    return answerCandidate[answerIdx];
}

