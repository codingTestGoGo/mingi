#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS(vector<vector<bool>>& isVisit, vector<vector<int>>& dist, vector<string>& map, int startX, int startY) 
{
    queue<pair<int, int>> q;
    q.push({startX, startY});
    isVisit[startX][startY] = true;
    dist[startX][startY] = 0;
    
    while( !q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        
        for(int i = 0; i <4; i ++) 
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            
            if ( nx < 0 || ny <0 || nx >= map.size() || ny >= map[0].length()) continue;
            
            if(isVisit[nx][ny] == false && map[nx][ny] != 'X')
            {
                isVisit[nx][ny] = true;
                dist[nx][ny] = dist[curX][curY] + 1;
                q.push({nx, ny});
            }
        }
        
    }
    
    return -1;
}


int solution(vector<string> maps) {
    int answer = 0;
    pair<int, int> lever;
    pair<int, int> start;
    pair<int, int> end;
    vector<vector<bool>> isVisit(100, vector<bool>(100, false));
    vector<vector<int>> dist (100, vector<int>(100, -1));
    
    for(int i = 0; i <maps.size(); i ++) 
    {
        for(int j = 0; j <maps[i].size(); j++) 
        {
            if ( maps[i][j] == 'L')
            {
                lever = {i, j};
            }
            else if (maps[i][j] == 'S')
            {
                start = {i, j};
            }
            else if (maps[i][j] == 'E')
            {
                end = {i, j};
            }
        }
    }
    
    BFS(isVisit, dist, maps, lever.first, lever.second );
    
    if (dist[start.first][start.second] == -1 || dist[end.first][end.second] == -1)
        return -1;
    answer = dist[start.first][start.second] + dist[end.first][end.second];
    
    return answer;
}