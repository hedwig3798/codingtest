#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

// dfs 함수
long long dfs(vector<vector<int>> &route_map, vector<long long> &a, vector<bool> &is_visit, int now, long long &answer){
    // 현재 노드 방문 처리
    is_visit[now] = true;
    
    // dfs 탐색
    for (auto i : route_map[now]){
        if (!is_visit[i])
            // 현재 노드의 가중치 조정
            a[now] += dfs(route_map, a, is_visit, i, answer);
    }
    
    // 현재 노드의 가중치를 가져옴
    long long val = a[now];
    // 정답에 절댓값을 더해서 연산 횟수 계산
    answer += abs(val);
    // 현재 노드 0 처리
    a[now] = 0;
    // 상위 노드 값 갱신을 위해 값 전달
    return val;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    // long long 형식으로 a 벡터 형변환
    vector<long long> aa;
    // 그래프
    vector<vector<int>> route_map(a.size());
    // 방문 여부 체크 벡터
    vector<bool> is_visit(a.size(), false);
    
    // 쌍방향 그래프 만들기
    for (auto i : edges){
        route_map[i[0]].push_back(i[1]);
        route_map[i[1]].push_back(i[0]);
    }
    
    // a 벡터 형변환
    for (auto i : a){
        aa.push_back((long long)i);
    }
    
    // 최종 결과값 받아오기
    long long temp = dfs(route_map, aa, is_visit, 0, answer);
    // 최종 결과값이 0이 아니라면 해당 트리는 0이 될 수 없다는 뜻이므로
    if (temp != 0)
        return -1;
    // 최종 결과값이 0이라면 연산 횟수 
    return answer;
}
