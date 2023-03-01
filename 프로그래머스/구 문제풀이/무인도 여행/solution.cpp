#include <bits/stdc++.h>

// 이미 지나간 곳인지 확인하기 위한 배열
bool is_visit[100][100] = {false, };

// 섬 순회 함수
int get_w (vector<string> &maps, int i, int j){
    // 인덱스가 범위 밖인경우 예외처리
    if (i < 0 || i >= maps.size() || j < 0 || j >= maps[0].size())
        return 0;
    // 이미 방문했거나 섬이 아닌경우
    if (maps[i][j] == 'X' || is_visit[i][j] == true)
        return 0;
    
    // 해당 섬의 숫자 구하기
    int result = maps[i][j] - '0';
    // 방문 사실 기록
    is_visit[i][j] = true;
    
    // 4방향으로 섬 순회
    result += get_w(maps, i+1, j);
    result += get_w(maps, i-1, j);
    result += get_w(maps, i, j+1);
    result += get_w(maps, i, j-1);
    
    // 결과를 리턴
    return result;
        
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    // 모든 섬을 순회
    for (int i = 0 ; i < maps.size() ; i++){
        for (int j = 0 ; j < maps[0].size() ; j++){
            // 이미 방문했거나 섬이 아니라면 conmtinue
            if (maps[i][j] == 'X' || is_visit[i][j] == true)
                continue;
            // 아니라면 섬의 숫자 합을 구하고 리턴
            answer.push_back(get_w(maps, i, j));
        }
    }
    // 정답 벡터에 아무것도 없다면 -1
    if (answer.size() == 0)
        answer.push_back(-1);
    // 아니라면 
    else
        sort(answer.begin(), answer.end());
    return answer;
}
