#include <string>
#include <vector>
#include <iostream>

using namespace std;


int answer = 0;


void DFS(int idx, vector<int>& members, vector<int>& number, vector<bool>& isVisit)
{
    if( members.size() == 3)
    {
        int scoreSum = 0;
        for(int i =0; i< 3; i ++)
        {
            scoreSum+= members[i];
        }
        if (scoreSum == 0) answer++;
        return;
    }
    
    for(int i = idx; i < number.size() ; i++)
    {
        if(isVisit[i] == false)
        {
            members.push_back(number[i]);
            isVisit[i] = true;
            DFS(i+1, members, number, isVisit);
            isVisit[i] = false;
            members.pop_back();
        }
    }
}

int solution(vector<int> number) {
    
    vector<int> members;
    vector<bool> isVisit(number.size(), false);
    DFS(0, members, number, isVisit);
    
    return answer;
}