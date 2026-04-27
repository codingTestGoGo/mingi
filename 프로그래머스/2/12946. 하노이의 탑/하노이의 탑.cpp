#include <string>
#include <vector>

using namespace std;

// a-> c로 n개의 원반을 옮긴다
void Hanoi(int n, int start, int end, int sub, vector<vector<int>>& answer)
{
    if( n==1)
    {
        answer.push_back({start, end});
        return;
    }
    
    // n-1 개를 1에서 2로 옮긴다
    Hanoi(n-1, start, sub, end, answer);
    answer.push_back({start, end});
    // n-1 개를 2에서 3으로 옮긴다
    Hanoi(n-1, sub, end, start, answer );
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    Hanoi(n, 1, 3, 2, answer);  // 1에서 3으로 2를 거쳐서옮긴다
    return answer;
}



// 3개의 원반 옮기기
// 1번 원반을 a에서 c로 옮김
// 2번 원반을 a에서 b로 옮김
// 1번 원반을 c에서 b로 옮김 

// 3번 원반을 a에서 c로 옮김 

// 1번 원반을 b에서 a로 옮김
// 2번 원반을 b에서 c로 옮김
// 1번 원반을 a에서 c로 옮김

// 3개의 원반을 옮기기 위해선
// 2개의 원반을 c를 거쳐서 b로 옮기고
// 3번 원반을 c로 옮기고
// 2개의 원반을 a를 거쳐 c로 옮기면면된다.
