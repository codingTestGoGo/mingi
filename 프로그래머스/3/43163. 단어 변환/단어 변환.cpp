#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int answer = 51;
void DFS(string curWord, string target, vector<string>& words, vector<bool>& isVisit, int depth)
{
    cout << "curWord: "<<curWord <<endl;
    cout << "DFS is, depth: "<< depth<< endl;
    if (curWord == target)
    {
        cout << depth << endl;
        answer = min(answer, depth);
        return ;
    }
    
    // words가 방문한 노드인지 확인
    for(int i = 0; i <words.size(); i ++)
    {
        if (isVisit[i] == true) continue;
        // 현재 단어랑 1글자가 다른지 검사
        int diffCnt = 0;
        
        for(int j = 0; j < curWord.length(); j++)
        {
            if (curWord[j] != words[i][j]) diffCnt++;
        }
        
        // 현재 단어랑 하나 차이날때만  dfs로 전달
        if (diffCnt == 1)
        {
            isVisit[i] = true;
            DFS(words[i], target, words, isVisit, depth+1);
            isVisit[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    vector<bool> isVisit(words.size(), false);
    if(find(words.begin(), words.end(), target) == words.end()) return 0;
    
    DFS(begin, target, words, isVisit, 0);
    
    return answer;
}