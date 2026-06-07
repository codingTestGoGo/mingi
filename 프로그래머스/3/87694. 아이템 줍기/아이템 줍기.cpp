#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(vector<vector<int>>& board, vector<vector<int>>& dist, int startX, int startY, int targetX, int targetY)
{
    queue<pair<int,int>> q;
    q.push({startX, startY});
    dist[startX][startY] = 0;
    
    while(!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        
        for(int i = 0; i <4; i ++)
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            
            if(nx <1 || ny <1 || nx >100 || ny >100) continue;
            
            // 방문한 적이 없고, 테두리 위의 점인경우
            if (dist[nx][ny] == -1 && board[nx][ny] == 1)
            {
                dist[nx][ny] = dist[curX][curY] + 1;
                q.push({nx, ny});
            }
        }
        
    }
}

// 사각형의 테두리르 먼저 그리고 겹치는 내부 테두리를 2로 채운다
void BoardSetting(vector<vector<int>>& rectangle, vector<vector<int>>& board)
{
    for(auto rect : rectangle)
    {
        int x1 = rect[0] * 2;
        int y1 = rect[1] * 2;
        int x2 = rect[2] * 2; 
        int y2 = rect[3] * 2;
        
        for(int i = x1; i <= x2 ; i++)
        {
            for(int j = y1; j <= y2 ;j++)
            {
                // 사각형의 변 위의 점
                if (i == x1 || i == x2 || j == y1 || j == y2)
                {
                    board[i][j] = 1;
                }
            }
        }
        
        for(int i = x1; i <=x2 ; i++)
        {
            for(int j = y1; j <= y2;j++)
            {
                // 사각형 내부
                if ( (i > x1 && i <x2 )&& (j > y1 && j < y2) )
                {
                    board[i][j] = 2;
                }
            }
        }
    }
    for(auto rect : rectangle)
    {
        int x1 = rect[0] * 2;
        int y1 = rect[1] * 2;
        int x2 = rect[2] * 2; 
        int y2 = rect[3] * 2;
        
        for(int i = x1; i <=x2 ; i++)
        {
            for(int j = y1; j <= y2;j++)
            {
                // 사각형 내부
                if ( (i > x1 && i <x2 )&& (j > y1 && j < y2) )
                {
                    board[i][j] = 2;
                }
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    vector<vector<int>> board(101, vector<int>(101, 0));
    vector<vector<int>> dist(101, vector<int>(101, -1));

    BoardSetting(rectangle, board);
    BFS(board, dist, characterX*2, characterY*2, itemX*2, itemY*2);

    answer = dist[itemX*2][itemY*2] /2 ;
    return answer;
}


















/*
 기존 bfs처럼 상하좌우를 검사하면, 1칸떨어진 블럭사이를점프하거나 두께가 1칸인 직사각형을 통과하는 문제가 생긴다
    => 좌표를 전부 2배로키워서 해결하고 답을 2로 나눈다. 
 좌표마다 모든 직사각형을 가지고 검사하는것보다 bfs를 돌기전에 직사각형의 정보를 맵에 입력해놓는게 좋다
*/