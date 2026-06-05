#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<bool>> reachability(101, vector<bool>(101, false));
    
    for(int i = 0; i <results.size(); i++)
    {
        int start = results[i][0];
        int end = results[i][1];
        reachability[start][end] = true;
    }
    
    // 플로이드로 거쳐서 도달할 수 잇는 노드 true 체크하기
    for(int k = 1; k <=n; k++)
    {
        for (int i = 1; i <=n; i++)
        {
            for(int j = 1; j<= n; j++)
            {
                if(reachability[i][k] && reachability[k][j])
                    reachability[i][j] = true;
            }
        }
    }
    
    for (int i = 1; i<= n; i++)
    {
        for(int j = 1; j<=n ; j++)
        {
            cout<<reachability[i][j];
        }
        cout << endl;
    }
    
    for(int i = 1; i <=n; i++)
    {
        int reachCnt = 0;
        for(int j = 1; j <=n; j++)
        {
            if (reachability[i][j] || reachability[j][i]) reachCnt++;
        }
        if (reachCnt == n-1) answer++;
    }
    
    return answer;
}