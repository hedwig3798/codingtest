#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    // times의 최소값을 얻기 위해
    sort(times.begin(), times.end());
    // 이분탐색의 시작과 끝 초기화
    long long start = (long long)times[0];
    long long end = (long long)n * (long long)times[0];
    // 정답을 최대치로 맞춤
    answer = (long long)n * (long long)times[0];
    
    // 이분탐색
    for (;start <= end;){
        // 중앙값 선정
        long long mid = (start + end) / 2;
        // 심사를 받은 사람 수
        long long human = 0;
        for (auto i : times){
            // 중앙값이 정답이라 가정하고 해당 시간 안에 심사를 받을 수 있는 사람의 수를 구함
            human += mid / i;
            
            // 구하는 도중 커지느 경우
            if (human >= n){
                // 최소값 (엄밀히 human == n인 경우지만 어차피 human > n 인 경우보다 뒤에 갱신되므로 상관이 없다.)
                answer = mid;
                // end 지점 옮기기
                end = mid-1;
                // 더 진행할 필요가 없다.
                break;
            }
        }
        // 반복을 다 해도 n보다 적은 사람이 심사를 받았다면 start 값 이동
        if (human < n){
            start = mid+1;
        }
    }
    
    
    
    return answer;
}
