// 총 판매금을 위로 올리는 경우의 코드
#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

// 얼마나 벌었는지
map<string, int> earn;
// 결과
map<string, int> result;
// 트리
map<string, vector<string>> tree;

// dfs함수
int dfs(string start){
    // 현재 사람이 판매한 금액
    int r = earn[start] * 100;
    // dfs를 돌려 아래 사람의 판매금의 일부를 더한다.
    for (auto i : tree[start]){
        r += dfs(i);
    }
    // 윗 사람에게 주는 판매금을 뺀 자신의 동
    result[start] = r - r/10;
    // 윗 사람에게 주는 돈
    return r/10;
}


vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer (enroll.size());
    // 얼마나 벌었는지
    for (int i = 0 ; i < seller.size() ; i++){
        earn[seller[i]] = amount[i];
        result[seller[i]] = 0;
    }
    
    // 트리 구조 만들기
    for (int i = 0 ; i < enroll.size() ; i++){
        tree[referral[i]].push_back(enroll[i]);
    }
    
    // center에서 dfs 시작
    dfs("-");
    
    // 정답 
    for (int i = 0 ; i < enroll.size() ; i++){
        answer[i] = result[enroll[i]];
    }
    return answer;
}
