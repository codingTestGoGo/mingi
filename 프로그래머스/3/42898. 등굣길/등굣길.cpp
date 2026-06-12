#include <string>
#include <vector>
#include <iostream>
#define MOD 1000000007

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> roadInform(n + 1, vector<int>(m + 1, 0));
    
    for(auto puddle: puddles)
    {
        int x = puddle[0];
        int y = puddle[1]; 
        roadInform[y][x] = -1;
    }
    
    for(int i =1; i<= n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            if (i == 1 &&j== 1) 
            {
                roadInform[i][j] = 1;
                continue;
            } 
            // 현재 도착한 인덱스가 물웅덩이인 경우
            if (roadInform[i][j] == -1) 
                continue;
            
            // 왼족 위쪽이 모두 물웅덩이인경우
            if( roadInform[i-1][j] == -1 && roadInform[i][j-1] == -1)
            {
                roadInform[i][j] = -1;
                continue;
            }
            // 왼쪽이 물웅덩이인 경우
            else if (roadInform[i][j-1] == -1)
            {
                roadInform[i][j] = roadInform[i-1][j] % MOD;
                continue;                
            }
            // 위쪽이 물웅덩이인 경우
            else if (roadInform[i-1][j] == -1)
            {
                roadInform[i][j] = roadInform[i][j-1] % MOD;
                continue;
            }
            // 이전경로에 물웅덩이가 없는경우
            else 
                roadInform[i][j] = (roadInform[i][j-1]%MOD + roadInform[i-1][j] %MOD)%MOD;
        }
    }

    /*
    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j <=m; j ++)
        {
            cout <<roadInform[i][j] << " ";
        }
        cout<<endl;
    }
    */
    
    answer = roadInform[n][m] % MOD;
    return answer;
}