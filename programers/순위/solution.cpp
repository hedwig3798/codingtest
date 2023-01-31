#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    // dfs용 스텍
    stack<int> s;
    // 전적 그래프
    vector<vector<int>> graph (n+1);
    // 전적 기록 벡터
    vector<pair<int, int>> rating (n+1, {0, 0});
    
    // 전적 그래프에 값 입력
    for (auto i : results){
        graph[i[0]].push_back(i[1]);
    }

    // dfs
    for (int i = 1 ; i < graph.size() ; i++){
        s.push(i);
        vector<int> is_visit (n+1, 0);
        
        for(;!s.empty();){
            int now = s.top();
            s.pop();
            for (auto j : graph[now]){
                if (is_visit[j] != 0)
                    continue;
                // i 노드에 1승씩 추가
                rating[i].first++;
                // j 노드에 1패씩 추가
                rating[j].second++;
                s.push(j);
                is_visit[j] = 1;
            }
        }
    }

    // 승 패 횟수 합이 n-1인 경우 순위가 정확하게 나올 수 있다.
    for (int i = 1 ; i < rating.size() ; i++){
        if (rating[i].first + rating[i].second == n-1)
            answer++;
    }
    
    return answer;
}
