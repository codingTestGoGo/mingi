#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    int left = 0;
    int right = people.size()-1;
    
    while(left <= right)
    {
        int curWeight = people[left] + people[right];
        
        if( curWeight > limit) 
        {
            answer++;
            right--;
        }
        else
        {
            answer++;
            left++;
            right--;
        }
    }
    
    
    return answer;
}

/*
limit의 절반과 각 요소들의 차이가 0에가까운것부터 정렬하여 2개씩 선택하면 되지않을가
무게가 낮은사람 + 높은 사람으로 태워야함
정렬해서 양쪽을 투포인터로 하나씩 O(n/2)
    무게가 넘치면 right를 하나땡기고
    무게가 충분하면 left right를 하나씩 땡기기
2개가 들어가면 뱉어야함
*/