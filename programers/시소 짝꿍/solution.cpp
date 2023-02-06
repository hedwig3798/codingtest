#include <bits/stdc++.h>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    // 각 무게를 가진 사람이 얼마나 들어가 있는지 체크하는 맵
    map<long long, long long> count;
    // 오름차순 정렬
    sort(weights.begin(), weights.end());
    for (auto i : weights){
        // 무게가 i인 사람과 i*2인 사람의 수를 더함
        answer += count[i] + count[i*2];
        // 그외 조건에 맞는 "정수"무게를 가진 사람을 구함
        if (i % 2 == 0)
            answer += count[i/2];
        if ((i*2) % 3 == 0)
            answer += count[(i*2)/3];
        if ((i*3) % 2 == 0)
            answer += count[(i*3)/2];
        if ((i*4) % 3 == 0)
            answer += count[(i*4)/3];
        if ((i*3) % 4 == 0)
            answer += count[(i*3)/4];
        // 현재 사람을 맵에 
        count[i] += 1;
    }
    
    return answer;
}
