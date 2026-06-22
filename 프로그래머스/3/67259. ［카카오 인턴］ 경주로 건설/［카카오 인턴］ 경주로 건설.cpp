#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define MAX 1000000000

using namespace std;

// hor: 0, ver:1
// 남동 북서 
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    queue<pair<int,int>> q;
    vector<vector<vector<bool>>> isVisit(2, vector<vector<bool>>(n, vector<bool>(n, false)));
    vector<vector<vector<int>>> cost(2, vector<vector<int>>(n, vector<int>(n, MAX)));
    cost[0][0][0] = cost[1][0][0] = 0;
    isVisit[0][0][0] = isVisit[1][0][0] = true;
    q.push({0, 0});
    
    while(!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        int horCost = cost[0][curX][curY];
        int verCost = cost[1][curX][curY];
        q.pop();
        
        for(int i = 0 ; i <4; i++)
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            
            if(nx <0 || ny<0 || nx >= n || ny >= n) continue; 
            
            if (board[nx][ny] != 1)
            {
                // 위, 아래로 이동
                if((i == 0 || i== 2) && min(horCost + 600, verCost+ 100) < cost[1][nx][ny])
                {
                    isVisit[1][nx][ny] = true;
                    q.push({nx, ny});
                    cost[1][nx][ny] = min(horCost + 600, verCost+ 100);
                }
                
                // 좌우로 이동
                else if ((i == 1 || i== 3) && min(horCost + 100, verCost+ 600) < cost[0][nx][ny])
                {
                    isVisit[0][nx][ny] = true;
                    q.push({nx, ny});
                    cost[0][nx][ny] = min(horCost + 100, verCost + 600);
                }
            }
        }
    }
    
    /*
    for(int i = 0; i <n;i ++)
    {
        for(int j = 0; j <n;j ++)
        {
            if(min(cost[0][i][j], cost[1][i][j])  == MAX) 
                cout << 0 << " ";
            else
                cout<< min(cost[0][i][j], cost[1][i][j]) << " ";
        }
        cout << endl;
    }
    */
    
    answer = min(cost[0][n-1][n-1], cost[1][n-1][n-1]);
    return answer;
}

/*
일직선으로 들어오는 값. 코너를 꺾어 들어오는 값 두개 값을 모두 가지고 있어야 하나?
재방문은 고려할필요가없나 
 => 맞음 (무조건 더 비싸질테니까) 다만, 가로, 세로 방향마다 방문을 세주긴해야함

*/