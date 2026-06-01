#include <string>
#include <vector>

using namespace std;
int answer = 0;

void DFS(int idx, int target, int curNum, vector<int>& numbers)
{
    if( idx == (numbers.size()) && curNum == target)
    {
        answer++;
        return;
    }
    else if(idx == numbers.size()) return;
    
    DFS(idx+1, target, curNum+numbers[idx], numbers);
    DFS(idx+1, target, curNum-numbers[idx], numbers);
}

int solution(vector<int> numbers, int target) {
    DFS(0, target, 0, numbers);   
    
    return answer;
}

// 모든숫자의 조합 + 부호 선택 2개
// dfs를 2개 호출, 첫번째 인덱스 - , + 로 각각하나씩 호출