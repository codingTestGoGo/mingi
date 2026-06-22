#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};

bool CanGo(vector<vector<int>>& rectangle, int a, int b)
{
    //cout << a << " " << b <<endl;
    bool isOnLine = false;
    
    for(auto rect : rectangle)
    {
        // 사각형 내부에 잇는가
        if( a > rect[0] && a < rect[2] && b > rect[1] && b < rect[3]) return false;
        // 내부에 없고 선 위에잇는가
        else if ( (a == rect[0] || a == rect[2]) && b >= rect[1] && b <= rect[3]) isOnLine = true;
        else if ( (b == rect[1] || b == rect[3]) && a >= rect[0] && a <= rect[2]) isOnLine = true;
    }
    if(isOnLine)
        return true;
    else return false;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    queue<tuple<int, int, int>> q;
    vector<vector<bool>> isVisit(101, vector<bool>(101, false));
    
    for(int i =0; i <rectangle.size(); i++)
    {
        for(int j = 0; j < 4; j++)
        {
            rectangle[i][j] *= 2;
        }
    }
    
    q.push({characterX, characterY, 0});
    isVisit[characterX][characterY]= true;
    
    while(!q.empty())
    {
        int curX = get<0>(q.front());
        int curY = get<1>(q.front());
        int curDist = get<2>(q.front());
        q.pop();
        
        //cout << curX << " " << curY << endl;
        
        if (curX == itemX && curY == itemY)
        {
            answer = curDist/2;
            break;
        }
        
        for(int i = 0; i <4; i++)
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= 101 || ny >= 101 ) continue;
            
            if (CanGo(rectangle, nx, ny) && isVisit[nx][ny] == false) 
            {
                q.push({nx, ny, curDist+1});
                isVisit[nx][ny] = true;
            }
        }
    }
    
    return answer;
}

// 조건식이 까다로운 문제
// 직사각형의 두께가 1이될때 통과하는문제를 해결해야함
// 좌표를 2배시켜서 해결한다
// 사각형의 내부에 있지 않더라도, 모든 사각형의 외부에 잇는 경우를 세 줘야한다
// => 사각형 내부에 존재하지 않으면서 적어도 하나 이상의 사각형의 변 위에 존재해야 한다