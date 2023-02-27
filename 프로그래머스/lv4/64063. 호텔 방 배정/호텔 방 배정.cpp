#include <bits/stdc++.h>

const int INF = 987654321;

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    unordered_map<long long, long long> uf;
    
    long long ind = 0;
    for (auto i : room_number){
        long long now = i;
        vector <long long> temp;
        temp.push_back(now);
        
        for(;uf.find(now) != uf.end();){
            now = uf[now];
            temp.push_back(now);
        }
        
        answer.push_back(now);
        for (auto j : temp){
            uf[j] = now+1;
        }
        temp.clear();
    }
    return answer;
}