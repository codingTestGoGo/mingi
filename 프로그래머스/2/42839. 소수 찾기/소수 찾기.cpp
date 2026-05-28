#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <stdlib.h>
#include <algorithm>

using namespace std;

bool isPrime [10000000];

int solution(string numbers) {
    int answer = 0;
    memset(isPrime, true, 10000000);
    for(int i = 2 ; i < 3162; i++)
    {
        if(isPrime[i] == true)
        {
            for(int j = i*2; j<10000000; j+= i)
            {
                isPrime[j] = false;
            }
        }
    }
    sort(numbers.begin(), numbers.end(), greater<char>());
    int maxNumber = stoi(numbers);
    
    cout << isPrime[9999999];
    
    string targetStr;
    
    for(int curNum = 2; curNum < 10000000; curNum++)
    {
        if(isPrime[curNum] == false) continue;
        if(curNum > maxNumber) break;
        targetStr = to_string(curNum);
        
        sort(targetStr.begin(), targetStr.end(), greater<char>());
        
        int numPtr = 0;
        int primePtr = 0;
        
        while(1)
        {
            if(primePtr == targetStr.length())
            {
                answer++;
                break;
            }
            else if (numPtr == numbers.length())
            {
                break;
            }
            
            if (numbers[numPtr] == targetStr[primePtr])
            {
                primePtr++;
                numPtr++;
                continue;
            }
            else if (numbers[numPtr] != targetStr[primePtr])
            {
                numPtr++;
                continue;
            }
        }
    }
    
    return answer;
}


// 천만 에라체 제작
// numbers 내림차순정렬
// 그거보다 낮은 소수 리스트업
// 소수를 스트링화
// 스트링 원소를 numbers가 모두 갖고 잇는지 대비
// 전부 오름차순 정렬해서 인덱스 초기화 안하고 대비해서 대비가 모두 통과되면 answer ++ ;