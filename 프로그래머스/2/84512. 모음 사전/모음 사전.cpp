#include <string>
#include <vector>

using namespace std;

int weight[5] = {781, 156, 31, 6, 1};

int solution(string word) {
    int answer = 0;
    answer += word.length();
    for(int i = 0; i <word.length(); i ++)
    {
        switch(word[i])
        {
            case 'A':
                answer += weight[i] * 0;
                break;
            case 'E':
                answer += weight[i] * 1;
                break;
            case 'I':
                answer += weight[i] * 2;
                break;
            case 'O':
                answer += weight[i] * 3;
                break;
            case 'U':
                answer += weight[i] * 4;
                break;
        }
    }
    
    return answer; 
}