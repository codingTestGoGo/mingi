#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// union을 합친다.
void IntegrateNetwork(int overWriter, int overWrited, vector<int>& unionFind)
{
    for(int i = 0;i <unionFind.size(); i++)
    {
        if (unionFind[i] == overWrited)
        {
            unionFind[i] = overWriter;
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> unionFind (computers.size());
    
    for(int i = 0; i <unionFind.size(); i++)
    {
        unionFind[i] = i + 1;
    }
    
    for( int i = 0; i < computers.size(); i++)
    {
        for( int j = 0; j <computers[i].size(); j++)
        {
            // 자신이 아닌 무언가와 연결되어 있을때
            if (computers[i][j] == 1 && i != j && unionFind[i] != unionFind[j]) 
            {
                IntegrateNetwork(unionFind[i], unionFind[j], unionFind);
            }
        }
    }
    
    for(int i = 0; i <unionFind.size(); i++)
    {
        cout << unionFind[i];
    }
    
    sort( unionFind.begin(), unionFind.end());
    int curNet = -1;
    // 유니온의 값이 다르다면 네트워크의 개수를 추가한다.
    for(int i = 0; i <unionFind.size() ; i ++)
    {
        if( curNet != unionFind[i] )
        {
            curNet = unionFind[i];
            answer++;
        }
    }
    
    return answer;
}