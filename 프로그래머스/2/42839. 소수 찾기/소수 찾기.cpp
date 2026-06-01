#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;
    
int answer = 0;
set<int> primeNumbers;

void DFS(string numbers, vector<bool>& isPrime, string curString, vector<bool>& isVisit)
{
    cout << curString << endl; 
    if(curString != "")
    {
        int curNum = stoi(curString);
        if (isPrime[curNum] == true && primeNumbers.find(curNum) == primeNumbers.end()) 
        {
            cout << curNum << endl;
            primeNumbers.insert(curNum);
        }
    }
    
    if (curString.length() == numbers.length()) return;
    
    for(int i = 0; i <numbers.size(); i++)
    {
        if(isVisit[i] == false)
        {
            isVisit[i] = true;
            DFS(numbers, isPrime, curString + numbers[i], isVisit); 
            isVisit[i] = false;
        }
    }
}

int solution(string numbers) {
    sort(numbers.begin(), numbers.end(), greater<char>());
    int n = 9999999;
    int sqrtN = sqrt(n);
    vector<bool> isPrime(n+1, true);
    vector<bool> isVisit(numbers.size(), false);
    
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <sqrtN ;i ++)
    {
        if(isPrime[i] == true)
        {
            //cout << i << endl;
            for(int j = i * 2 ; j <isPrime.size(); j +=i)
            {
                isPrime[j] = false;
            }
        }
    }
    
    DFS(numbers, isPrime, "", isVisit);
    answer = primeNumbers.size();
    
    return answer; 
}

// 가장 큰 수 의 루트 크기의 에라체를 만들어서 선형탐색
// char 벡터를 쓰면 빼고 끼는게 자유롭다 다만 int 화시킬때 어렵다
// string을 쓰면 인트화시키가 쉬운데 문자 하나를 빼는게 어렵다