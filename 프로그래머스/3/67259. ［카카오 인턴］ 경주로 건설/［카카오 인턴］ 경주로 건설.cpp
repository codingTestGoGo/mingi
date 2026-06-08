#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <tuple>
#define MAX 100000000

using namespace std;

int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};

// dir = 1 세로, dir=2 가로
void Dijkstra(vector<vector<int>>& board, vector<vector<vector<int>>>& dist, int n)
{
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 0;
    
    while(!q.empty())
    {
        int curX = get<0>(q.front());
        int curY = get<1>(q.front());
        int dir = get<2>(q.front());
        q.pop();
        
        for(int i = 0; i <4; i ++)
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            int nDir, nDist;
            
            if (i == 0 || i == 2) nDir = 1;
            else nDir = 2;
            
            nDist = (nDir == dir) ? 100 : 600; 
            
            if(nx <0 || ny < 0 || nx >= n || ny >= n || board[nx][ny] == 1) continue;
            
            if(dir == 0)
            {
                q.push({nx, ny, nDir});
                dist[nDir][nx][ny] = 100;
            }
            else if (dist[nDir][nx][ny] > dist[dir][curX][curY] + nDist)
            {
                q.push({nx, ny ,nDir});
                dist[nDir][nx][ny] = dist[dir][curX][curY] + nDist;
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0; 
    int n = board.size();
    vector<vector<vector<int>>> dist(3,vector<vector<int>>(n, vector<int>(n, MAX)));
    Dijkstra(board, dist, n);
    
    
    for(int i = 0; i <3; i++)
    {
        for(int j = 0; j <n; j++)
        {
            for(int k = 0; k < n ; k ++)
            {
                cout << " ";
                if(dist[i][j][k] == MAX) cout << 0;
                else cout <<dist[i][j][k];
            }
            cout << endl;
        }
        cout <<endl;
    }
    
    
    answer = min(dist[1][n-1][n-1], dist[2][n-1][n-1]);
    
    
    return answer;
}