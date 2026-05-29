#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map <string, int> map;

// 중복없이 모든 오름차순 조합 구하기
void DFS(string order, string temp, int idx)
{
    if(temp.size() > order.size()) return;
    
    map[temp]++;
    for(int i = idx; i <order.size() ; i++)
    {
        DFS(order, temp+order[i], i + 1); 
    }
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(auto order : orders)
    {
        sort(order.begin(), order.end());
        DFS(order, "", 0);
    }
    for(auto courseOrder : course)
    {
        int mostOrdered = 0;
        
        for(auto order: map)
        {
            if(order.first.length() != courseOrder) continue;
            mostOrdered = max(mostOrdered, order.second);
        }
        
        if (mostOrdered < 2) continue;
        
        for (auto order: map)
        {
            if(order.second == mostOrdered && order.first.length() == courseOrder)
            {
                answer.push_back(order.first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

/*
order 들을 정렬한다.
각 order로 만들 수 있는 모든 조합을 map에 저장한다.
course의 숫자마다 가장 많은 주문횟수를 가지는 코스를 answer에 넣는다.
*/