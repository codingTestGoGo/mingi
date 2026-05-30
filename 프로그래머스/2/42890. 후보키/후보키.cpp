#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> map;
unordered_map<string, int> uniqueMap;
vector<string> allData;
string column = "01234567";

void DFS(int idx, string temp, int columnLen)
{
    if(temp.length() > columnLen) return;
    
    map[temp]++;
    for(int i = idx; i <columnLen; i++)
    {
        DFS(i+1, temp+column[i], columnLen);
    }
}

bool AddToUnique(string strToAdd)
{
    for(auto str : uniqueMap)
    {
        // 중복된게 이미 map 에 있다면
        int equal = 0;
        for(int i = 0; i <str.first.length() ; i++)
        {
            for(int j = 0; j <strToAdd.length(); j++)
            {
                if(str.first[i] == strToAdd[j])
                {
                    equal++;
                    break;
                }
            }
        }
        if(equal == str.first.length()) return false;  
    }
    uniqueMap[strToAdd]++;
    return true;
}

bool Comp(string& a, string& b)
{
    if(a.length() == b.length())
    {
        return a < b;
    }
    else
    {
        return a.length() < b.length();
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    cout << relation[0].size() <<"\n\n";
    
    DFS(0, "", relation[0].size());         // 모든 컬럼조합 저장
    
    for(auto columnData : map)
    {
        allData.push_back(columnData.first); 
    }
    
    sort(allData.begin(), allData.end(), Comp);
    
    for(auto curData : allData)
    {
        unordered_map<string, int> tempMap;
        // 행 순환
        for(int j = 0; j<relation.size(); j++)
        {
            string curTuple = "";
            // 열들의 데이터 조합
            for(int i = 0; i<curData.length(); i ++)
            {
                int curColumn = curData[i] - '0';
                curTuple = curTuple + relation[j][curColumn];
            }
            
            // 튜플값 넣어서 확인하기 
            if(tempMap.find(curTuple) != tempMap.end()) // 이미 안에 튜플이 잇다? 중복이라면
            {
                tempMap.clear();
                break;
            }
            else
            {
                tempMap.insert({curTuple, 0});
            }
        }
        // 유일해
        if(tempMap.empty()== false)
        {
            // 처음보는 유일임
            if(AddToUnique(curData))
            {
                answer++;
            }
        }
    }    
    return answer;
}


/*
column이 8개이므로 중복없이 모든컬럼 조합을 만든다.
모든 조합에 대해서 맵에 넣고, 중복이 없으면 count
다만,최소성 만족이 문젠데
짧은것부터 map에 추가하고 추가하기 전에 map의 모든 요소들에 대해서 find연산을 통해서 중복이 잇는지검사하면 될것
*/