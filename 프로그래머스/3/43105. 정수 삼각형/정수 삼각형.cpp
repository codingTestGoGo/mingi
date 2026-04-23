#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<vector<int>> dp;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    dp.resize(triangle.size()) ; 
    
    for(int i = 0; i < triangle.size(); i ++)
    {
        dp[i].resize(i + 1);    
    }
    
    dp[0][0] = triangle[0][0];
    cout << dp[0][0];
    
    
    for(int i = 1; i <dp.size(); i++)
    {
        for(int j = 0; j <dp[i].size() ; j++)
        {
            if ( j == 0)
            {
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }
            else if( j == i)
            {
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
            }
            
            answer = max( answer, dp[i][j]);
        }
    }
    
    
    return answer;
}