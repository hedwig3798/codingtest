#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = INF;
    int max_alp = alp;
    int max_cop = cop;
    int MAX = 151;
    int dp[MAX][MAX];
    
    fill(&dp[0][0], &dp[MAX - 1][MAX], INF);
    
    for (auto i : problems){
        max_alp = max(max_alp, i[0]);
        max_cop = max(max_cop, i[1]);
    }
    
    problems.push_back({0, 0, 0, 1, 1});
    problems.push_back({0, 0, 1, 0, 1});
    
    if (alp >= max_alp && cop >= max_cop)
        return 0;
    
    dp[alp][cop] = 0;
    for (int i = alp ; i <= max_alp ; i++){
        for (int j = cop ; j <= max_cop ; j++){
            if (i == max_alp && j == max_cop){
                return dp[i][j];
            }
            
            for (auto p : problems){
                int req_alp = p[0];
                int req_cop = p[1];
                int up_alp = p[2];
                int up_cop = p[3];
                int time = p[4];
                
                if (i < req_alp || j < req_cop)
                    continue;
                
                int algo = (i+up_alp > max_alp) ? max_alp : i+up_alp;
                int coding = (j+up_cop > max_cop) ? max_cop : j+up_cop;
                
                dp[algo][coding] = min(dp[algo][coding], dp[i][j] + time);         
            }
        }
    }
    
    return answer;
}