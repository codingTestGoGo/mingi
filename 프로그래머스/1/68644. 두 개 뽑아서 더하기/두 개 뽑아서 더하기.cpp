#include <string>
#include <vector>
#include <algorithm>
#include <set> 

using namespace std;
set<int> sumTwoNum;


void DFS(int idx, vector<int>& numbers, vector<int>& selected)
{
    if(selected.size() == 2)
    {
        sumTwoNum.insert(selected[0] + selected[1]);
        return;
    }
    
    for(int i = idx; i <numbers.size(); i ++)
    {
        selected.push_back(numbers[i]);
        DFS(i+1, numbers, selected);
        selected.pop_back();
    }
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> selected;
    
    DFS(0, numbers, selected);
    //sort(sumTwoNum.begin(), sumTwoNum.end());
    
    for(auto num : sumTwoNum)
    {
        answer.push_back(num);
    }
        
    return answer;
}