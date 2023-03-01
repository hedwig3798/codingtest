#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    // 배달해야 되는 개수
    long long d = 0;
    // 수거해야 되는 개수
    long long p = 0;
    for (int i = n-1 ; i >= 0 ; i--){
        // 현재 위치를 몇번 들려야 하는지
        long long count = 0;
        // 현재 위치에서 배달하는 개수
        d += deliveries[i];
        // 현재 위치에서 수거하는 개수
        p += pickups[i];
      
        // 각 개수가 모두 0 이하가 되는 경우 이 지역에 더이상 올 필요가 없으므로
        for (;d > 0 || p > 0;){
            // 들려야 하는 반복 횟수 카운트
            count++;
            // 갯수에서 cap 만큼 빼서 배달 및 수거할 수 있는 갯수를 카운트
            d -= cap;
            p -= cap;
        }
        // 정답 
        answer += (i + 1) * 2 * count;
    }
    
    return answer;
}
