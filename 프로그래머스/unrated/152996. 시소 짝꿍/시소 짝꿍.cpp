#include <bits/stdc++.h>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<long long, long long> count;
    sort(weights.begin(), weights.end());
    for (auto i : weights){
        answer += count[i] + count[i*2];
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

        count[i] += 1;
    }
    
    return answer;
}