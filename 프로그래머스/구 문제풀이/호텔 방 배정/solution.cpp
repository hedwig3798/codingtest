#include <bits/stdc++.h>

const int INF = 987654321;

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    // hash_map
    // c++ 에는 hash_map 자료구조가 있지만, 프로그래머스에서 지원하는 컴파일러에는 해당 자료구조로 되어있다.
    unordered_map<long long, long long> uf;
    
    // 정답 벡터 인덱스
    long long ind = 0;
    for (auto i : room_number){ 
        // 들어갈 방
        long long now = i;
        // 한번 들른 방을 기록할 벡터
        vector <long long> temp;
        // 현재 방을 들렸으므로 벡터에 입력
        temp.push_back(now);
        
        // 만일 방에 사람이 있다면 없을 때 까지 반복
        for(;uf.find(now) != uf.end();){
            // 사람이 있다면 그 방의 다음 방을 찾음
            now = uf[now];
            // 그 방을 들렸으므로 기록
            temp.push_back(now);
        }
        
        // 정답에 해당 빈방을 기록
        answer.push_back(now);
        // 들렸던 방의 다음 빈방 기록
        for (auto j : temp){
            uf[j] = now+1;
        }
        // 임시 벡터 정리
        temp.clear();
    }
    return answer;
}
