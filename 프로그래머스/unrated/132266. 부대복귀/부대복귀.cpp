#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> route_map(n+1, vector<int>());
    vector<int> is_visit (n+1, 0);
    for (auto i : roads){
        route_map[i[0]].push_back(i[1]);
        route_map[i[1]].push_back(i[0]);
    }
    
    for (auto s : sources){
        int count = 0;
        queue<int> q;
        vector<int> is_visit (n+1, -1);
        
        q.push(s);
        is_visit[s] = 0;
        int now = s;
        for (;;){
            if (q.empty()){
                break;
            }
            else if (!q.empty()){
                now = q.front();
                q.pop();
                if (now == destination)
                    break;
                for (auto i : route_map[now]){
                    if (is_visit[i] == -1){
                        q.push(i);
                        is_visit[i] = is_visit[now] + 1;
                    }
                }
                
            }
        }
        answer.push_back(is_visit[destination]);
    }
    
    return answer;
}