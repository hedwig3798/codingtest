#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    stack<int> s;
    vector<vector<int>> graph (n+1);
    vector<pair<int, int>> rating (n+1, {0, 0});
    
    for (auto i : results){
        graph[i[0]].push_back(i[1]);
    }

    for (int i = 1 ; i < graph.size() ; i++){
        s.push(i);
        vector<int> is_visit (n+1, 0);
        
        for(;!s.empty();){
            int now = s.top();
            s.pop();
            for (auto j : graph[now]){
                if (is_visit[j] != 0)
                    continue;
                rating[i].first++;
                rating[j].second++;
                s.push(j);
                is_visit[j] = 1;
            }
        }
    }

    for (int i = 1 ; i < rating.size() ; i++){
        if (rating[i].first + rating[i].second == n-1)
            answer++;
    }
    
    return answer;
}