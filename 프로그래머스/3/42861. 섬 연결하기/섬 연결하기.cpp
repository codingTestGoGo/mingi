#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool Compare(vector<int>& a, vector<int>& b)
{
    return a[2] < b[2];
}

int Find(vector<int>& parents, int target)
{
    if (parents[target] == target) 
    {
        return target;
    }
    return Find(parents, parents[target]);
}

bool Union(vector<int>& parents, int a, int b)
{
    int rootA = Find(parents, a);
    int rootB = Find(parents, b);
    
    cout << "root " << rootA << " rootB: "<< rootB<<endl;
    
    if (rootA == rootB) return false;
    else
    {
        parents[rootB] = rootA;
        
        for(int i = 0;i <20; i ++)
        {
            cout << parents[i];
        }
        cout <<endl;
        
        return true; 
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> parents(100);
    for(int i = 0; i <n; i++)
        parents[i] = i;
    
    sort(costs.begin(), costs.end(), Compare);
    
    for(auto cost : costs)
    {
        int start = cost[0];
        int end = cost[1];
        int dist = cost[2];
        
        if( Union(parents, start, end))
        {
            answer += dist;
        }
    }
    
    return answer;
}