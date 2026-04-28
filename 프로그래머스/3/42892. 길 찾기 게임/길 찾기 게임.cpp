#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Tree
{
    int x;
    int y;
    int idx;
    Tree* left = NULL;
    Tree* right = NULL;
};

bool Compare(const vector<int>& a, const vector<int>& b)
{
    // 만약 y값이 같다면 x값이 작은게 우선
    if(a[1] == b[1])
    {
        return a[0] < b[0];
    }
    // 그렇지 않다면 y값이 큰게 우선이다.
    else
    {
        return a[1] > b[1];
    }
}

void PreOrder(Tree* node, vector<vector<int>>& answer)
{
    answer[0].push_back( node->idx);
    if(node->left != NULL)
    {
        PreOrder(node->left, answer);
    }
    if(node->right != NULL)
    {
        PreOrder(node->right, answer);
    }
}

void PostOrder(Tree* node, vector<vector<int>>& answer)
{
    if(node->left != NULL)
    {
        PostOrder(node->left, answer);
    }
    if(node->right != NULL)
    {
        PostOrder(node->right, answer);
    }
    
    answer[1].push_back(node->idx);
}

void MakeBinary(Tree* root, Tree* child)
{
    if(root== NULL) return;
    
    if(child->x < root->x)
    {
        if(root->left == NULL)
        {
            root->left = child;
            return;
        }
        else MakeBinary(root->left, child);
    }
    else
    {
        if(root->right == NULL)
        {
            root->right = child;
            return;
        }
        else MakeBinary(root->right, child);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    vector<Tree> tree;
    
    for(int i =0; i <nodeinfo.size(); i++)
    {
        nodeinfo[i].push_back(i+1);
    }
    
    sort(nodeinfo.begin(), nodeinfo.end(), Compare);
    
    for(int i =0 ;i <nodeinfo.size(); i++)
    {
        tree.push_back( {nodeinfo[i][0], nodeinfo[i][1], nodeinfo[i][2]});
    }
    
    Tree* root = &tree[0];

    
    for(int i =1; i <tree.size(); i++)
    {
        MakeBinary(root, &tree[i]);
    }
    
    
    PreOrder(root, answer);
    PostOrder(root, answer);
    
    return answer;
}


// 전위 순회
// 부모-left - right
// y가 가장 높은 노드를 방문한다
// 그 다음으로 높은 노드 중 x가 작은 것을 방문한다.
// 가장 낮은 높이라면, 해당 높이의 노드를 순서대로 방문한다.

// 후위 순회
// left - right - 부모
// y가 가장 높은 루트부터시작
// 다음으로 높은 노드들을 방문한다.
// 현재가 가장 낮은 노드라면, 현재 노드를 방문하고 리턴한다.

// 특정 노드기준으로 자식노드를 어떻게 찾을것인가?
// 노드정보는 y기준 내림, x기준 오름으로 되어있다.
// => 정렬하면 인덱스가 박살나서 불가능하네 
// => 정렬하기전에 백터 뒷부분에 인덱스를 추가해주면 된다
// 노드의 y값이 바뀌는 기준으로 자식을 판단하는데, 자신의 형제의 자식도 포함될수잇고, 형제의 자식의 y 좌표가 자신의 자식의 y좌표보다 높은경우 이상한 노드를 가져올 수 잇음 
// => tree 구조체를 만들어서 루트 노드부터 차근차근내려가면서 해당 노드가 누구의 자식인지 판단
