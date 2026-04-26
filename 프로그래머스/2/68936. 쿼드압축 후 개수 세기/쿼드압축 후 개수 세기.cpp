#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int totalZero = 0;
int totalOne= 0;

void QuadCompress(int x, int y, int size, vector<vector<int>>& map)
{
    int oneCnt = 0;
    int zeroCnt = 0;
    
    for(int i =x;i < x+ size ; i++)
    {
        for(int j = y; j< y + size ; j++)
        {
            if (map[i][j] == 1) oneCnt++;
            else if( map[i][j] == 0) zeroCnt++;
        }
    }
    
    if(oneCnt !=0 && zeroCnt != 0)
    {
        QuadCompress(x, y, size/2, map);
        QuadCompress(x, y+size/2, size/2, map) ;
        QuadCompress(x + size/2, y, size/2, map);
        QuadCompress(x + size/2, y + size/2, size/2, map);
        return;
    }
    else
    {
        oneCnt > 0 ? totalOne++ : totalZero++;
        return;
    }
    
    return;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    int n = arr.size();

    QuadCompress(0, 0, n, arr);
    answer[0] = totalZero;
    answer[1] = totalOne;
    return answer;
}

