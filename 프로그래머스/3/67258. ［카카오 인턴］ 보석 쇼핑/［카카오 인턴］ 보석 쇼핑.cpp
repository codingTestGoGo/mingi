#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string, int> gemStates;
    int gemKindCnt = unordered_set<string>(gems.begin(), gems.end()).size();
    int left = 0;
    int right = 0;
    int answerLeft = 0;
    int answerRight = gems.size() -1;
    
    for(int right = 0; right < gems.size(); right++)
    {
        gemStates[gems[right]]++;
        
        while(gemStates.size() == gemKindCnt)
        {
            if (answerRight - answerLeft > right - left)
            {
                answerRight = right;
                answerLeft = left;
            }
            
            gemStates[gems[left]]--;
            
            if(gemStates[gems[left]] == 0)
            {
                gemStates.erase(gems[left]);
            }
            
            left++;
        }
    }
    
    answer.push_back(answerLeft + 1);
    answer.push_back(answerRight + 1);
    return answer;
}