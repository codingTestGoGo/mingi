#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    char op;
    int value;
    map <int, int> pqList;
    
    for(auto operation : operations)
    {
        istringstream parse(operation);
        parse >> op >> value;
        
        switch(op)
        {
            case 'I':
                pqList[value]++;
                break;
            case 'D':
                if (pqList.empty()) break;
                
                if(value == 1)
                {
                    auto iter = pqList.end();
                    iter--;
                    
                    if(iter->second > 1)
                        iter->second--;
                    else
                        pqList.erase(iter);
                }
                else if ( value == -1)
                {
                    auto iter = pqList.begin();
                    
                    if(iter->second > 1)
                        iter->second--;
                    else
                        pqList.erase(iter);
                }
                break;
        }
    }
    
    if(pqList.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(pqList.rbegin() -> first);
        answer.push_back(pqList.begin() ->first);
    }
    
    return answer;
}

// 넣을 때마다 정렬 해줘야함
// 넣자마자 자동정렬.. 정렬이 빠른 구조.  map or set. . . 근데 추적, 삭제도 빨라야됨