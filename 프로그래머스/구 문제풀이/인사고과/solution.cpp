#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

// 비교함수
// 근무태도를 내림차순으로 정렬, 만일 같다면 동료평가를 오름차순으로 정렬
bool cmp(vector<int> a, vector<int> b){
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] > b[0];
}

int solution(vector<vector<int>> scores) {
    int answer = 0;
    // 완호의 값 미리 추출
    pair<int, int> wanho = {scores[0][0], scores[0][1]};
    int wanho_s = wanho.first + wanho.second;
    
    // 정렬
    sort(scores.begin(), scores.end(), cmp);
    
    // 최솟값 설정
    int min_score = 0;
    // 모든 스코어 순회
    for (auto i : scores){
        // 만일 최솟값 보다 동료평가가 적다면 과락
        // 이미 근무태도 순으로 내림차순 되어 있기 때문에 이전 동료들은 모두 근무태도가 높다
        if (i[1] < min_score){
            // 만일 완호의 점수와 같다면 완호는 과락이다.
            if (i[0] == wanho.first && i[1] == wanho.second)
                return -1;
            continue;
        }
        // 아니라면
        else {
            // 최소치 갱신
            min_score = i[1];
            // 만일 완호의 점수 합 보다 큰 경우 완호의 순위는 밀린다.
            if (i[0] + i[1] > wanho_s)
                answer++;
        }
    }
    
    // 0순위에서 시작했으므로 1 더해주어야 한다.
    return answer+1;
}
