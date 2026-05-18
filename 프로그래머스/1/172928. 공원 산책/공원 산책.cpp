#include <iostream>
#include <string>
#include <vector>

using namespace std;

// s, e, n, w
int dx [4] = {1, 0, -1, 0};
int dy [4] = {0, 1, 0, -1};
int startX, startY;
int height, width;
void ExecuteMove(int idx, int dist, vector<string>& park)
{
    cout << "dist : " << dist<< endl;
    
    int finalX = startX;
    int finalY = startY;
    
    for(int i =0;i <dist; i ++)
    {
        int nx = finalX + dx[idx];
        int ny = finalY + dy[idx];
        
        if(nx < 0 || ny <0 || nx >= height || ny >= width) return;
        else if (park[nx][ny] == 'X') return;
        else
        {
            finalX = nx;
            finalY = ny; 
            cout <<startX << " "<< startY <<endl;
        }
        
    }
    
    startX = finalX;
    startY = finalY;
    
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    char direction; 
    int dist;
    
    height = park.size();
    width = park[0].length();
    
    for(int i =0; i<park.size();i ++)
    {
        for(int j = 0; j <park[i].length(); j++)
        {
            if (park[i][j] == 'S')
            {
                startX = i;
                startY = j;
                break;
            }
        }
    }
    
    for(int i =0; i < routes.size(); i++)
    {
        direction = routes[i][0];
        dist = routes[i][2] - '0';
        
        switch(direction)
        {
            case 'S':
                ExecuteMove(0, dist, park);
                break;
            case 'E':
                ExecuteMove(1, dist, park);
                break;
            case 'N':
                ExecuteMove(2, dist, park);
                break; 
            case 'W':
                ExecuteMove(3, dist, park);
                break;
        }
        
    }
    
    answer.push_back(startX);
    answer.push_back(startY);
    return answer;
}