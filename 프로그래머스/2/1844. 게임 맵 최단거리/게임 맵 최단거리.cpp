#include<vector>
#include<queue>
#include<algorithm>
#include <iostream>

using namespace std;

int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};

int BFS(vector<vector<int>>& maps, vector<vector<int>>& dist, int n, int m)
{
    queue<pair<int, int>> q;
    
    q.push({0,0});
    dist[0][0] = 1;
    
    while(!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        
        if ( curX == n && curY == m)
        {
            return dist[n][m];
        }
        
        for(int i = 0;i < 4; i++)
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            
            if(nx < 0 || ny < 0 || nx > n || ny > m) continue;
            
            if (maps[nx][ny] != 0 && dist[nx][ny] == 0 )
            {
                dist[nx][ny] = dist[curX][curY] +1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    vector<vector<int>> dist(maps.size(), vector<int>(maps[0].size(), 0));
    int n = maps.size()-1;
    int m = maps[0].size() -1;
    int answer = 0;
    answer = BFS(maps, dist, n, m);
    return answer;
}