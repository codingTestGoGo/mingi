#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void Parser(vector<string>& info, vector<vector<string>>& applicants, string delimeter)
{
    int start = 0;
    int end;
    for(int i = 0; i < info.size() ; i++)
    {
        start = 0;
        info[i] += delimeter;
        end = info[i].find(delimeter, start);
        while( end != string::npos)
        {
            string parsed = info[i].substr(start, end - start);
            if( parsed != "and" )
                applicants[i].push_back(parsed);        // " "까지 끊기
            start = end + delimeter.length();
            end = info[i].find(delimeter, start);
            
        }
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<vector<string>> applicants(info.size());
    vector<vector<string>> parsedQuery(query.size());
    map<string, vector<int>> appliDB;
    
    Parser(info, applicants, " ");
    Parser(query, parsedQuery, " ");
    
    // map에 해당 지원자가 설정될 수 잇는 모든 쿼리를 key로 추가하고 value에 점수를 입력한다.
    for(auto applicant : applicants) 
    {
        appliDB[applicant[0] + applicant[1] + applicant[2] + applicant[3]].push_back(stoi(applicant[4]));
        for(int i = 1;i <=4;i ++)
        {
            vector<bool> comb(4, false);
            for(int k = 0 ; k <i ; k++)
                comb[k] = true;
            do
            {
                string temp = "";
                for(int j = 0; j < 4; j++ )
                {
                    if (comb[j]) temp+= "-";
                    else temp += applicant[j];
                }
                appliDB[temp].push_back(stoi(applicant[4]));
            } while(prev_permutation(comb.begin(), comb.end()));
        }
    }
    
    
    for(auto& item: appliDB)
    {
        sort(item.second.begin(), item.second.end());
    }
    
    for(auto query: parsedQuery)
    {
        string key = query[0] + query[1] + query[2] + query[3];
        vector<int>& scores = appliDB[key];
        vector<int>::iterator iter = lower_bound(scores.begin(), scores.end(), stoi(query[4]));
        answer.push_back(scores.end() - iter);
    }
    
    return answer;
}

/*
info의 지원자를 전부 파싱하긴해야 한다.
파싱한 지원자 각각에 대해서 지원자가 포함될 수있는 모든 쿼리를 맵에 넣어줘야한다.
    맵에 들어간 지원자의 점수는 오름차순으로 정렬한다.
쿼리를 순회하면서 각 쿼리를 key값으로 거기에 저장된 점수값을 이분탐색, 만족시키는 지원자의 수를 센다

*/