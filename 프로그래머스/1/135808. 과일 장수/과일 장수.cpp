#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end(), greater<int>());
    
    int index = m-1;
    

    while(1)
    {
        if (index >= score.size()) break;
        answer += score[index] * m;
        index += m ;
    }
    
    return answer;
    
}

// 444 444 222 211