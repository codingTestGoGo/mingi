#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool Compare(vector<int>& a, vector<int>& b)
{
    return a[0] > b[0];
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> accumulatedSum (n, vector<int>(m, 0));
    
    for(int i = 0; i <skill.size(); i++)
    {
        int attackType = skill[i][0];
        int x1 = skill[i][1];
        int y1 = skill[i][2];
        int x2 = skill[i][3];
        int y2 = skill[i][4];
        int value = skill[i][5];
        if(attackType == 1) value = -value;
        
        accumulatedSum[x1][y1] += value;
        if (x2 == n-1 && y2 == m-1)
            continue;
        if (y2 < m-1)
            accumulatedSum[x1][y2+1] -= value;
        if (x2 < n-1)
            accumulatedSum[x2+1][y1] -= value;
        if (x2 < n-1 && y2 < m-1)
            accumulatedSum[x2+1][y2+1] += value;
    }
    
    // 가로 순회
    for(int i = 0; i<n; i ++)
    {
        for(int j = 1; j <m; j++)
        { 
            accumulatedSum[i][j] += accumulatedSum[i][j-1];
        }
    }
    
    // 세로 순회
    for (int i = 0; i < m; i++)
    {
        for(int j = 1; j<n; j++)
        {
            accumulatedSum[j][i] += accumulatedSum[j-1][i];
        }
    }
    
    for(int i = 0;i <board.size(); i++)
    {
        for(int j = 0; j<board[0].size(); j ++)
        {
            if (board[i][j] + accumulatedSum[i][j] > 0) answer++;
        }
    }
    
    return answer;
}