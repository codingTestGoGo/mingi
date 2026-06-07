#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, int> FindWall(vector<string>& board, int idx, int curX, int curY)
{
    int dirX = dx[idx];
    int dirY = dy[idx];
    int nx = curX;
    int ny = curY;
    while(1)
    {
        nx += dirX;
        ny += dirY;
        
        if(board[nx][ny] == 'D')
        {
            nx -= dirX;
            ny -= dirY;
            break;
        }
        else if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].length())
        {
            nx -= dirX;
            ny -= dirY;
            break;
        }
    }
    
    return {nx, ny};
}

int BFS(vector<string>& board, vector<vector<int>>& dist, int startX, int startY)
{
    queue<pair<int, int>> q;
    q.push({startX, startY});
    dist[startX][startY] = 0;
    
    while(!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        
        if (board[curX][curY] == 'G') return dist[curX][curY];
        
        for(int i = 0; i <4; i++) 
        {
            pair<int, int>next = FindWall(board, i, curX, curY);
            int nx = next.first;
            int ny = next.second;
            
            if( nx== curX && ny == curY) continue;
            
            if(dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[curX][curY] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    int startX, startY;
    vector<vector<int>> dist(100, (vector<int>(100, -1)));
    
    for(int i = 0; i <board.size(); i++)
    {
        for(int j = 0; j<board[i].length(); j++)
        {
            if( board[i][j] == 'R')
            {
                startX = i;
                startY = j;
            }
        }
    }
    
    answer = BFS(board, dist, startX, startY);
    return answer;
}