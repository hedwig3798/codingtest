#include <bits/stdc++.h>

const int INF = INT_MAX / 2;
using namespace std;

struct compare{
     bool operator()(pair<int, int> a, pair<int, int> b){
         return a.second > b.second;
     }
};

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    vector<vector<pair<int, int>>> route(n+1);
    vector<bool> is_top(n+1);
    vector<bool> is_start(n+1);
    
    for (auto i : paths){
        route[i[0]].push_back({i[1], i[2]});
        route[i[1]].push_back({i[0], i[2]});
    }
    for (auto i : gates){
        is_start[i] = true;
    }
    for (auto i : summits){
        is_top[i] = true;
    }
    
    sort(summits.begin(), summits.end());
    
    for (auto i : gates){
        priority_queue <pair<int, int>, vector<pair<int, int>>, compare> pq;
        vector<int> dik(n+1, INF);
        vector<bool> is_visit(n+1, false);

        dik[i] = 0;
        pq.push({i, 0});
        
        for (;!pq.empty();){
            auto now = pq.top();
            pq.pop();
            
            if (is_top[now.first]){
                if (answer.empty()){
                    answer.push_back(now.first);
                    answer.push_back(dik[now.first]);
                }
                else {
                    if (answer[1] > dik[now.first]){
                        answer[0] = now.first;
                        answer[1] = dik[now.first];
                    }
                    else if (answer[1] == dik[now.first] && answer[0] > now.first){
                        answer[0] = now.first;
                        answer[1] = dik[now.first];
                    }
                }
                continue;
            }
                
            if (now.second > dik[now.first])
                continue;
            
            for (auto j : route[now.first]){
                if (is_start[j.first])
                    continue;
                if (dik[j.first] < j.second)
                    continue;

                int temp = max(dik[now.first], j.second);
                
                if (temp >= dik[j.first])
                    continue;
                if (!answer.empty() && temp > answer[1])
                    continue;
                dik[j.first] = temp;
                pq.push(j);
            }
        }
    }

    return answer;
}