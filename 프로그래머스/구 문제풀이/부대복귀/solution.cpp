#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    // 루트 맵의 그래프화 (링크 리스트 그래프)
    vector<vector<int>> route_map(n+1, vector<int>());
    
    // 그래프 작성
    for (auto i : roads){
        route_map[i[0]].push_back(i[1]);
        route_map[i[1]].push_back(i[0]);
    }
    
    // 각 대원들의 위치 마다 bfs 시작
    for (auto s : sources){
        // bfs용 큐
        queue<int> q;
        // 방문 여부 및 거리 저장 (-1 : 미방문, 그 외 방문에 필요한 거리)
        vector<int> is_visit (n+1, -1);
        
        // 초기값
        q.push(s);
        is_visit[s] = 0;
        int now = s;
        for (;;){
            // 큐가 비어있으면 끝
            if (q.empty()){
                break;
            }
            else if (!q.empty()){
                // 큐에서 한 값을 pop
                now = q.front();
                q.pop();
                // 그곳이 목적지라면 끝
                if (now == destination)
                    break;
                // bfs
                for (auto i : route_map[now]){
                    // 아직 방문하지 않았다면
                    if (is_visit[i] == -1){
                        // 큐에 값을 넣음
                        q.push(i);
                        // 거리 값을 갱신
                        is_visit[i] = is_visit[now] + 1;
                    }
                }
                
            }
        }
        // bfs 종료 후 destination에 있는 값이 
        answer.push_back(is_visit[destination]);
    }
    
    return answer;
}
