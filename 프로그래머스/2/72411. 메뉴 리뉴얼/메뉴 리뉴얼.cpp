#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

set<string> allCourses;
unordered_map<string, int> overlapedCourse;

void DFS(string order, string curCombination, int curCourse, int idx)
{
    if(curCombination.length() == curCourse)
    {
        // 없으면  
        if (allCourses.find(curCombination)== allCourses.end())
        {
            allCourses.insert(curCombination);
        }
        else
        {
            overlapedCourse[curCombination]++;
        }
        return;
    }
    
    for(int i = idx; i <order.length() ; i++)
    {
        DFS(order, curCombination + order[i], curCourse, i+1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i = 0;i <orders.size(); i ++)
    {
        sort(orders[i].begin(), orders[i].end());
        
        cout <<orders[i] << endl;
    }
    for(int i = 0; i <course.size(); i++)
    {
        for(auto order: orders)
        {
            DFS(order, "", course[i], 0);
        }
        
        int maxCnt = 0;
        for(auto course: overlapedCourse)
        {
            maxCnt = max(maxCnt, course.second);
        }
        for(auto course: overlapedCourse)
        {
            if (course.second == maxCnt)
            {
                answer.push_back(course.first);
            }
        }
        
        allCourses.clear();
        overlapedCourse.clear();
    }

    sort(answer.begin(), answer.end());
    
    return answer;
}

// course 와 길이가 똑같은 것들중에, 중복되는 문자열을 넣어야한다.
// 길이가 같은 모든 문자열들을 만들고 unorderedmap에 넣는다.
// 이걸