#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers) {
    // 정답 벡터의 사이즈를 미리 정해 놓음
    vector<int> answer (numbers.size());
    // 인덱스와 숫자 정보가 들어갈 스텍
    stack<pair<int, int>> s;
    
    for (int i = 0 ; i < numbers.size() ; i++){
        // 스텍이 비어 있다면 값을 입력
        if (s.empty()){
            s.push({i, numbers[i]});
        }
        else {
            // 스텍이 비어있지 않고 top값이 현재 번호보다 작다면 반복
            for (;!s.empty() && s.top().second < numbers[i];){
                // 스텍 pop
                auto temp = s.top();
                s.pop();
                // pop한 값의 인덱스 위치에 현재 숫자를 넣음
                answer[temp.first] = numbers[i];
            }
            // 현재 값을 스텍에 입력
            s.push({i, numbers[i]});
        }
    }
    
    // 스텍에 값이 남아 있다면 뒷큰수가 없는 수 이므로 -1을 넣음
    for (;!s.empty();){
        auto temp = s.top();
        s.pop();
        answer[temp.first] = -1;
    }
    
    
    return answer;
}
