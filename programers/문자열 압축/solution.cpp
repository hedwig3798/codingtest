#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

int solution(string s) {
    // 정답의 최대치 선정
    int answer = INF;
    
    // 절반 + 1 까지만 가도 충분한 순회가 되므로
    for (int i = 1 ; i < s.length()/2 + 2 ; i++){
        // 첫 문자열 입력
        int count = i;
        string old = s.substr(0, i);
        // 반복 플래그
        int flag = 0;
        for(int j = i ; j < s.length() ; j += i){
            // 현재 문자열
            string now = s.substr(j, i);
            // 같다면 flag를 더하고 재귀
            if (old == now){
                flag++;
                continue;
            }
            // 만일 flag가 0이 아니라면 flag의 자릿수만큼 문자열이 늘어나므로 더해준다.
            if (flag != 0){
                flag++;
            }
            for ( ; flag > 0 ; ){
                count++;
                flag = flag/10;
            }
            
            // 현재 문자열 길이를 더한다.
            count += now.length();
            // 이전 문자열 정보 최신화
            old = now;
            // 반복 정보 최신화
            flag = 0;
        }
        
        // 마지막에 반복될 수 있으므로
        if (flag != 0){
            flag++;
        }
        for ( ; flag > 0 ; ){
            count++;
            flag = flag/10;
        }
        // 압축된 최종 문자열과 정답 중 최솟값 
        answer = min(answer, count);
    }
    return answer;
}
