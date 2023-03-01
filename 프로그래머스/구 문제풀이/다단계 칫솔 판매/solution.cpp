#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    // 미리 정답의 크기를 정해 놓음
    vector<int> answer (enroll.size());
    // 각 사람이 얼마나 벌었는지
    map<string, int> result;
    // 어떤 사람에게 추천 받았는지
    map<string, string> tree;

    // 추천 정보와 결과 정보 초기화
    for (int i = 0 ; i < enroll.size() ; i++){
        tree[enroll[i]] = referral[i];
        result[enroll[i]] = 0;
    }
    
    // 각 판매 마다 실행
    for (int i = 0 ; i < seller.size() ; i++){
        // 판매자 이름
        string sell = seller[i];
        // 판매 금액
        int mount = amount[i] * 100;
        
        // 판매 금액이 0이 되거나 판매자가 center가 되는경우 끝
        for (;mount > 0 && sell != "-";){
            // 현재 판매자가 가져가는 금액 더하기
            result[sell] += mount - mount/10;
            // 판매금 10%
            mount /= 10;
            // 다음 판매자로 윗사람 가져오기
            sell = tree[sell];
        }
    }
    // 정답 
    for (int i = 0 ; i < enroll.size() ; i++){
        answer[i] = result[enroll[i]];
    }
    
    return answer;
}
