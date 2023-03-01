#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    vector<int> flag; // 한번 순회 하였는지
    vector<vector<int>> c; // 사이클 저장 벡터
    flag.assign(cards.size(), 0); // cards 크기 만큼 flag 준비
    
    // cards를 순회하며 사이클 생성
    for (int i = 0; i < cards.size(); i++){
      
        // 이미 순회한 카드면 스킵
        if (flag[i] != 0){
            continue;
        }
        
        // 순회하지 않은 경우 사이클 찾기
        else {
            c.push_back(vector<int>());
            c.back().push_back(cards[i]);
            flag[i]++;
            // 사이클 만들어서 저장
            while(1){
                int now = c.back().back();
                if (flag[now-1] != 0){
                    break;
                }
                c.back().push_back(cards[now-1]);
                flag[now-1] ++;
            }
        }
    }
    // 정답 제출을 위한 벡터
    vector<int> ccc;
    
    // 벡터의 사이즈를 저잘
    for (vector<int> t : c){
        ccc.push_back(t.size());
    }
    
    // 벡터의 사이즈를 정렬
    sort(ccc.rbegin(), ccc.rend());
    
    // 사이클이 한개 이하인 경우 점수는 0점
    if (c.size() <= 1){
        return 0;
    }
    
    // 그외 점수 
    return ccc[0] * ccc[1];
}
