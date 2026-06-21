#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<string, vector<int>> applicantDB;
    
    for(auto inf: info)
    {
        // stringstream으로 info 파싱
        vector<string> parsedInfo(5);
        istringstream iss(inf);
        iss >> parsedInfo[0] >> parsedInfo[1] >> parsedInfo[2] >> parsedInfo[3] >> parsedInfo[4];
        //applicantDB[parsedInfo[0] + parsedInfo[1] +parsedInfo[2] + parsedInfo[3]].push_back(stoi(parsedInfo[4]));
        
        // 비트마스킹으로 해당지원자를 포함할 수잇는 모든 쿼리등록
        for(int mask = 0; mask<16 ; mask++)
        {
            string temp = "";
            
            for(int k = 0; k<4; k++)
            {
                temp += (mask & (1 << k)) ? "-" : parsedInfo[k];
            }
            //cout << temp << endl;
            applicantDB[temp].push_back(stoi(parsedInfo[4]));
        }
    }
    
    for(auto& applicant : applicantDB)
    {
        sort(applicant.second.begin(), applicant.second.end());
    }
    
    //쿼리 순회 및 이분탐색
    for(auto quer : query)
    {
        vector<string> parsedQuery;
        istringstream iss(quer);
        string parsedPiece;
        while(iss>>parsedPiece)
            if(parsedPiece != "and")
                parsedQuery.push_back(parsedPiece);
        vector<int>& scores = applicantDB[parsedQuery[0] + parsedQuery[1] + parsedQuery[2] + parsedQuery[3]];
        vector<int>::iterator iter = lower_bound(scores.begin(), scores.end(), stoi(parsedQuery[4]));
        answer.push_back(scores.end() - iter);
    }
    
    return answer;
}