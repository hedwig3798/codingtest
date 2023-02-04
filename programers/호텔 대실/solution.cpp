#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    // 누적합 배열 가장 늦은 시간인 23:59 에 10분을 더한 값 만큼 공간을 잡아 놓는다.
    int timeline[23*60 + 59 + 10] = {0, };
    // 누적합 값 입력
    for (auto time : book_time){
        int start = 0;
        int end = 0;
        
        start += stoi(time[0].substr(0, 2)) * 60;
        start += stoi(time[0].substr(3, 4));
        
        end += stoi(time[1].substr(0, 2)) * 60;
        end += stoi(time[1].substr(3, 4));
        
        timeline[start] += 1;
        // 정리시간을 포함한 퇴실시간을 입력한다.
        timeline[end + 10] -= 1;
    }
    //  누적합을 구하면서 가장 큰 값을 구하면 그것이 필요한 방의 수 이다.
    for (int i = 1 ; i < 23*60 + 59 + 10 ; i++){
        timeline[i] += timeline[i-1];
        answer = max(answer, timeline[i]);
    }
    
    return answer;
}
