#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> isConnected (n , vector<bool>(n, false));
    
    for(auto result : results)
    {
        int start = result[0] - 1;
        int end = result[1] - 1;
        isConnected [start][end] = true;
    }
    
    for(int k = 0; k <n; k++) 
    {
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j <n; j ++)
            {
                if (i == j ) continue;
                else if (isConnected[i][k] && isConnected[k][j])
                    isConnected[i][j] = true;
            }
        }
    }
    
    for(int i = 0; i <n; i ++)
    {
        int cnt = 0;
        for(int j = 0; j <n; j++)
        {
            if (i == j) continue;
            else if (isConnected[i][j] || isConnected[j][i])
                cnt++;
        }
        if (cnt == n-1)
            answer ++;
    }
    
    return answer;
}

// 특정 선수에 대해서 순위를 매기려면 다른 모든선수와의 승패결과를 알아야한다.
// 해당 선수와 연결된 엣지의 개수가 n-1개여야 함을 의미한다.