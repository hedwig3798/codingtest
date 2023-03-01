#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    // 그래프가 담길 벡터
    vector<vector<int>> graph (n, vector<int>());
    
    // 엣지를 연결하여 그래프화
    for (auto i : edge){
        graph[i[0]-1].push_back(i[1]-1);
        graph[i[1]-1].push_back(i[0]-1);
    }
    
    // bfs용 큐
    queue<int> q;
    // 거리정보가 담길 벡터
    vector<int> dis(n, -1);
    // 시작지점 선정
    dis[0] = 0;
    q.push(0);
    
    // 큐가 빌 때까지
    for (;!q.empty();){
        // 큐 pop
        int now = q.front();
        q.pop();
      
        // bfs하면서 거리 정보 업데이트
        for (auto i : graph[now]){
            if (dis[i] == -1){
                dis[i] = dis[now] + 1;
                q.push(i);
            }
        }
    }
    
    // 거리순 정렬
    sort(dis.begin(), dis.end(), greater<int>());
    
    // 거리의 최댓값
    int temp = dis[0];
    // 거리의 최댓값과 같은 수가 얼마나 
    for (auto i : dis){
        if (i == temp)
            answer++;
        else
            break;
    }
    
    return answer;
}
