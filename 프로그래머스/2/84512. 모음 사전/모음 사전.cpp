#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
string vowel = "AEIOU";

int solution(string word) {
    int answer = 0;
    int a = word.size();
    
    for(int i =0, b = 1; i<word.size() ; i++, b*=5)
    {
        a += vowel.find(word[i]) * 781 / b;
    }
    
    return a;
}