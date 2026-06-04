#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

// 특정 인덱스의 부모를 
int Find(vector<int>& parents, int curIdx)
{
    // 현재인덱스의부모가 자기 자신이라면 값을 리턴
    if(parents[curIdx] == curIdx)
    {
        return curIdx;
    }
    
    // 아니라면 계속 추적해서 루트 인덱스를 찾는다
    return Find(parents, parents[curIdx]);
}

void Union(vector<int>& parents, int a, int b)
{
    int rootA = Find(parents, a);
    int rootB = Find(parents, b);
    
    cout << "rootA: " << rootA << "rootB: " << rootB <<endl;
    
    if (rootA != rootB)
    {
        parents[rootB] = rootA;
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> parents(computers.size());
    
    // 부모를 자기 자신으로 초기화
    for(int i = 0; i < parents.size() ; i++) 
    {
        parents[i] = i;
    }
    
    for(int i = 0; i <computers.size(); i ++)
    {
        for(int j = 0; j <computers[i].size(); j++)
        {
            // 연결이 되어잇으면 통합 시도
            if( i != j && computers[i][j] == 1)
            {
                Union(parents, i, j);
                
                cout << "parents" <<endl;
                for(int i = 0; i <parents.size(); i ++)
                {
                    cout << parents[i];
                }
                cout <<endl;
            }
        }
    }
    
    cout << "parents" <<endl;
    for(int i = 0; i <parents.size(); i ++)
    {
        cout << parents[i];
    }
    cout << endl;
    
    set<int> nodes;
    for(int i = 0; i < parents.size(); i++)
    {
        if(Find(parents, i) == i)
        {
            nodes.insert(i);
        }
    }
    
    for(auto node : nodes)
    {
        cout << node; 
    }
    answer = nodes.size();
    return answer;
}