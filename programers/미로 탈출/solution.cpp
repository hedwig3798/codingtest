#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

// bfs 함수
int bfs(pair<int, int> start, vector<string> &maps, char flag){
    // 얼마가 걸리는지 리턴
    int result = 0;
    // 최대 크기 맵으로 방문 여부 확인
    int is_visit[101][101] = {0, };
    
    // bfs에 사용될 큐
    queue<pair<int, int>> q;
    // 시작점 초기화
    q.push(start);
    is_visit[start.first][start.second] = 1;
    
    // bfs 시작
    for (;!q.empty();){
        // queue pop
        pair<int, int> now = q.front();
        q.pop();
        // 만일 도착지라면 최단거리값을 반환하고 리턴
        if (maps[now.first][now.second] == flag){
            result = is_visit[now.first][now.second];
            return result;
        }
        // 아니라면 4방향으로 확인
        else {
            // 경계값인지 확인
            if (now.first > 0){
                // 아니라면 벽이 아닌지와 이미 방문한 적이 있는지 체크
                if (maps[now.first-1][now.second] != 'X' && is_visit[now.first-1][now.second] == 0){
                    // 둘 다 아니라면 큐에 넣고 방문 여부 체크
                    q.push({now.first-1, now.second});
                    is_visit[now.first-1][now.second] = is_visit[now.first][now.second]+1;
                }
            }
            // 이하 동일
            if (now.first < maps.size()-1){
                if (maps[now.first+1][now.second] != 'X' && is_visit[now.first+1][now.second] == 0){
                    q.push({now.first+1, now.second});
                    is_visit[now.first+1][now.second] = is_visit[now.first][now.second]+1;
                }
            }
            if (now.second > 0){
                if (maps[now.first][now.second-1] != 'X' && is_visit[now.first][now.second-1] == 0){
                    q.push({now.first, now.second-1});
                    is_visit[now.first][now.second-1] = is_visit[now.first][now.second]+1;
                }
            }
            if (now.second < maps[0].size()-1){
                if (maps[now.first][now.second+1] != 'X' && is_visit[now.first][now.second+1] == 0){
                    q.push({now.first, now.second+1});
                    is_visit[now.first][now.second+1] = is_visit[now.first][now.second]+1;
                }
            }
        }
    }
    return result;
}

int solution(vector<string> maps) {
    int answer = -1;
    
    pair<int, int> start;
    pair<int, int> end;
    pair<int, int> lever;
    
    // 시작점 끝점 레버의 위치를 파악
    for (int i = 0 ; i < maps.size() ; i++){
        for (int j = 0 ; j < maps[0].size() ; j++){
            if (maps[i][j] == 'S')
                start = {i, j};
            else if (maps[i][j] == 'E')
                end = {i, j};
            else if (maps[i][j] == 'L')
                lever = {i, j};
        }
    }
    // 시작 -> 레버, 레버 -> 끝점 까지의 길이 파악
    int stol = bfs(start, maps, 'L');
    int ltoe = bfs(lever, maps, 'E');
    
    // 만일 둘 중 하나라고 못하게 되면 -1 리턴
    if (stol == 0 || ltoe == 0)
        return -1;
    
    // 둘 다 정상 도착이 되면 값을 더하고 
    answer = stol + ltoe - 2;

    
    return answer;
}
