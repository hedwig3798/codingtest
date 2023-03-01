#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

// dfs 함수
void dfs(vector<vector<int>> &users, vector<int> &emoticons, vector<int> &discount, vector<int> &disinfo, vector<vector<int>> &able, int depth){
    // 탈출조건
    if (depth == emoticons.size()){
        // 가입자 수와 모든 사용자의 구매 금액
        int join = 0;
        int buy = 0;
        for (auto u : users){
            // 해당 사용자의 구매 금약
            int cost = 0;
            // 모든 이모티콘 가격 계산
            for (int e = 0 ; e < emoticons.size() ; e++){
                // 해당 유저가 생각하는 할인율 이상인 경우에만 구매
                if (u[0] <= disinfo[e]){
                    cost += emoticons[e] - (emoticons[e] * ((float)disinfo[e]/100));
                }
            }
            // 만일 총 구매 금액이 유저 생각보다 많다면 가입
            if (cost >= u[1]){
                join++;
            }
            // 아니라면 그냥 구매
            else {
                buy += cost;
            }
        }
        // 가능한 경우의 수 추가
        able.push_back({join, buy});
    }
    // 재귀
    else {
        // 가능한 모든 할인률 적용
        for (auto d : discount){
            // 현재 단계에 적용
            disinfo[depth] = d;
            // 재귀
            dfs(users, emoticons, discount, disinfo, able, depth+1);
        }
    }
}

// 경우의 수 비교 함수
bool cmp(vector<int>a, vector<int> b){
    // 만일 가입자 수가 같다면 가격 우선
    if (a[0] == b[0])
        return a[1] > b[1];
    // 아니라면 가입자 순 내림차순
    else
        return a[0] > b[0];
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    // 할인률
    vector<int> discount = {10, 20, 30, 40};
    // 각 이모티콘에 적용될 할인률
    vector<int> disinfo(emoticons.size());
    // 경우의 수
    vector<vector<int>> able;
    
    // 가능한 경우의 수 완전탐색
    dfs(users, emoticons, discount, disinfo, able, 0);  
    
    // 정렬
    sort(able.begin(), able.end(), cmp);
    
    // 정렬 결과 가장 앞에 있는 값이 
    return able[0];
}
