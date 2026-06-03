#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
string columns = "012345678";

void DFS(vector<string>& allColumn, int idx, int maxColumn, string curString)
{
    if(curString != "")
    {
        allColumn.push_back(curString);
    }
    
    for(int i = idx; i < maxColumn ; i++)
    {
        DFS(allColumn, i+1, maxColumn, curString+columns[i]);
    }
}

bool IsAnswer(vector<string>& answerCandidate, string strToAdd)
{ 
    // 정답에 들어잇는 모든 문자열 비교
    for(auto answer: answerCandidate)
    {
        int matchCnt = 0;
        // 정답문자열의 문자 하나하나를 추가할 문자열과비교
        // 추가할 문자열에 기존 정답의 문자열이 모두 포함되어잇으면 false 아니면 true
        for(int i = 0; i <answer.length(); i++)
        {
            for(int j = 0; j<strToAdd.length(); j++)
            {
                if(answer[i] == strToAdd[j])
                {
                    matchCnt++;
                    break;
                }
            }
        }
        
        if (matchCnt == answer.length())
        {
            return false;
        }
    }
    return true;
}

bool Compare(string& a, string& b)
{
    if(a.length() == b.length())
    {
        return a < b;
    }
    else
        return a.length() < b.length();
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<string> allColumn;
    vector<string> answerCandidate;
    
    DFS(allColumn, 0, relation[0].size(), "");
    sort(allColumn.begin(), allColumn.end(), Compare);
    
    for(auto curColumns : allColumn)
    {
        set<string> tupleInCurColumn;
        for(int i =0; i <relation.size(); i ++)
        {
            string curString;
            // 선택된 열의 문자열을 조립
            for(int j = 0; j <curColumns.length(); j++)
            {
                int idx = curColumns[j] - '0'; 
                curString += relation[i][idx];
            }
            // set에 중복된 열이 잇으면 break;
            if(tupleInCurColumn.find(curString) != tupleInCurColumn.end())
                break;
            else
                tupleInCurColumn.insert(curString);
        }
        
        // 튜플크기가 관계의 행과같으면 정답 중복 검사 실시
        if( tupleInCurColumn.size() == relation.size() && IsAnswer(answerCandidate, curColumns))
        {
            answerCandidate.push_back(curColumns);
        }
    }
    
    answer = answerCandidate.size();
    return answer;
}