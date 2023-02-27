#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

int solution(vector<int> stones, int k) {
    // 정답의 최대치. 제한 사항에 명시되어 있음
    int answer = 200000001;
    // 슬라이딩 윈도우에 사용될 덱
    deque<pair<int, int>> d;
    
    // k가 1인경우 최솟값 구하기 문제이므로
    if (k == 1){
        return *min_element(stones.begin(), stones.end());
    }
    
    // 슬라이딩 윈도우 알고리즘
    for (int i = 0; i < stones.size() ; i++){
        
        // 인덱스와 번호를 묶은 pair
        pair<int, int> temp = {i, stones[i]};
        // 덱이 비어있다면 (= 처음이라면) 값 넣기
        if (d.empty()){
            d.push_back(temp);
        }
        // 만일 덱의 끝이 지금 수 보다 크다면 덱에 수를 넣음
        else if (d.back().second >= temp.second){
            d.push_back(temp);
        }
        // 아니라면 덱의 끝이 더 크거나 덱이 빌 때까지 덱의 back 에서 pop 함
        else {
            for (;d.back().second < temp.second;){
                d.pop_back();
                if (d.empty())
                    break;
            }
            d.push_back(temp);
        }
        // 덱의 처음 부분이 인덱스를 벗어난 경우 front에서 pop함
        if (d[0].first <= i-k)
            d.pop_front();
        // 인덱스가 k 이상인경우 부터 정답을 갱신
        if (i >= k-1){
            answer = min(answer, d[0].second);
        }
    }
    
    return answer;
}