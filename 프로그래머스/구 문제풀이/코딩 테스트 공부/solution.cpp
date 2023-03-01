#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    // 초기 정답 값
    int answer = INF;
    // 각 능력 최대치의 초기값, 이렇게 하지 않으면 문제가 생긴다. 후술함
    int max_alp = alp;
    int max_cop = cop;
    // 제한사항 상 최대 점수가 150점 이므로
    int MAX = 151;
    // dp 배열
    int dp[MAX][MAX];
    // dp배열 초기화
    fill(&dp[0][0], &dp[MAX - 1][MAX], INF);
    
    // 문제에서 요구하는 능력의 최대치를 구함
    for (auto i : problems){
        max_alp = max(max_alp, i[0]);
        max_cop = max(max_cop, i[1]);
    }
    // 문제를 풀지 않고 공부하는 경우를 추가
    problems.push_back({0, 0, 0, 1, 1});
    problems.push_back({0, 0, 1, 0, 1});
    
    // 만일 바로 풀리는 경우
    if (alp >= max_alp && cop >= max_cop)
        return 0;
    
    // dp 시작점을 0으로 초기화
    dp[alp][cop] = 0;
    // 만일 위에서 요구능력 초기화를 잘못하는 경우 루프에 들어가지 못해 오류가 난다.
    for (int i = alp ; i <= max_alp ; i++){
        for (int j = cop ; j <= max_cop ; j++){
            // 만일 현재가 최대치인 경우 해당 값을 리턴
            if (i == max_alp && j == max_cop){
                return dp[i][j];
            }
            
            // 모든 문제에 대해
            for (auto p : problems){
                // 알아보기 쉽도록 배열 값의 이름 붙이기
                int req_alp = p[0];
                int req_cop = p[1];
                int up_alp = p[2];
                int up_cop = p[3];
                int time = p[4];
                
                // 만일 풀 수 없는 경우
                if (i < req_alp || j < req_cop)
                    continue;
                
                // 해당 문제를 풀 때 각 능력치가 어떻게 되는지
                // 최대치가 되는경우 최대치로 맞춰줌
                int algo = (i+up_alp > max_alp) ? max_alp : i+up_alp;
                int coding = (j+up_cop > max_cop) ? max_cop : j+up_cop;
                // 해당 능력치에 있는 값과 비교하여 최솟값을 남도록 함
                dp[algo][coding] = min(dp[algo][coding], dp[i][j] + time);         
            }
        }
    }
    
    return answer;
}
