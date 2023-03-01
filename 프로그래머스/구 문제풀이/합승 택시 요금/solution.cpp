#include <bits/stdc++.h>

using namespace std;
// 전체 그래프
// 접근을 훨씬 많이 하므로 배열을 사용함
// 길이는 제한사항의 최대치
int graph[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    // 임의의 최댓값
    int answer = 3000000;
    // 그래프를 임의의 최댓값으로 초기화
    fill(&graph[0][0], &graph[n][n], 3000000);
    
    // 그래프에 거리당 요금 정보를 입력
    // 양방향 이므로 양쪽으로 입력
    for (auto f : fares){
        graph[f[0]][f[1]] = f[2];
        graph[f[1]][f[0]] = f[2];  
    }
    
    // 자기 자신의 경우 0으로 초기화
    for (int i = 1 ; i < n+1 ; i++){
        graph[i][i] = 0;
    }
    
  
    // 와샬 플로이드 알고리즘
    // 해당 알고리즘을 거치면 x -> y 로 가는 최단 거리가 graph[x][y]에 담긴다
    // 거쳐가는 노드
    for (int k = 1 ; k < n+1 ; k++){
        // 출발 노드
        for (int i = 1 ; i < n+1 ; i++){
            // 도착 노드
            for (int j = 1 ; j < n+1 ; j++){
                if (graph[j][i] > graph[i][k] + graph[k][j])
                    graph[j][i] = graph[i][k] + graph[k][j];
            }
        }
    }
    
    // 전체 노드를 들린다 가정
    for (int i = 1 ; i < n+1 ; i++){
        // 같이 i 노드 까지 합승하여 감
        int temp = graph[s][i];
        // i 노드 에서 각자 집 노드로 감
        temp += graph[i][b];
        temp += graph[i][a];
        // 결과값을 비교하여 작은것을 선정
        answer = min(answer, temp);
    }
    
    return answer;
}
