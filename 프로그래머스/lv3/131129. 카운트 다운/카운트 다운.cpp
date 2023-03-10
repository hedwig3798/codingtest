#include <bits/stdc++.h>
const int INF = 987654321;


using namespace std;

vector<int> solution(int target) {
    vector<int> answer;
    vector<pair<int, int>> dp (100001, {INF, INF});
    int score[] = {1,18,4,13,6,10,15,2,17,3,19,7,16,8,11,14,9,12,5,20};
    
    for (int i = 0 ; i < 20 ; i++){
        dp[score[i] * 2] = {1, 0};
        dp[score[i] * 3] = {1, 0};
        
        dp[score[i]] = {1, 1};
    }
    for (int i = 0 ; i < 20 ; i++){
        dp[score[i]] = {1, 1};
    }
    dp[0] = {0, 0};
    dp[50] = {1, 1};
        
    for (int i = 1 ; i <= target ; i ++){
        int now_count = dp[i].first;
        int now_single = dp[i].second;
        
        for (int j = 1 ; j < i ; j++){
            int count = dp[j].first + dp[i-j].first;
            int single = dp[j].second + dp[i-j].second;
            if (now_count > count){
                dp[i] = {count, single};
                now_count = count;
                now_single = single;
            }
            else if(now_count == count && now_single < single){
                dp[i] = {count, single};
                now_count = count;
                now_single = single;
            }
        }
    }

    return {dp[target].first, dp[target].second};
}