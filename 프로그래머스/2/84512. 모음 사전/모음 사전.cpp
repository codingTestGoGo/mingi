#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

// 1, 5, 25, 125, 625
// 1, 6, 31, 156, 781

using namespace std;

int weight[5] = { 781, 156, 31, 6, 1 };

int solution(string word) {
    int answer;
    
    for(int i = 0; i <word.size(); i++)
    {
        int current;
        switch(word[i])
        {
            case 'A':
                current = 0;
                break;
            case 'E':
                current = 1;
                break;
            case 'I':
                current = 2;
                break;
            case 'O':
                current = 3;
                break;
            case 'U':
                current = 4;
                break;
        }
        
        answer += current * weight[i];
    }
    
    return answer;
}