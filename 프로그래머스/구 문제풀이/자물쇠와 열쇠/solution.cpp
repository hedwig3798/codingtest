#include <bits/stdc++.h>

using namespace std;

// 회전 함수
void rotate(vector<vector<int>> &key){
    // 임시 값을 받고
    vector<vector<int>> temp = key;
    // 시계방향으로 회전시킴
    for (int i = 0 ; i < key.size() ; i++){
        for (int j = 0 ; j < key.size() ; j++){
            key[i][j] = temp[key.size()-j-1][i];
        }
    }
    return;
}

// 정답 체크 함수
bool check(int check_lock[][60], int n){
    
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            // 안쪽에서 모두 1 이라면 빈틈 없이 열쇠가 들어간 것
            if (check_lock[i + n - 1][j + n - 1] == 1)
                continue;
            else
                return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    // 확장된 자물쇠 (3배)
    int check_lock [60][60] = {0, };
    // 자물쇠 공간을 모두 1로 채워넣음
    fill(&check_lock[0][0], &check_lock[59][60], 1);
    // 키의 크기와 자물쇠의 크기
    int kn = key.size();
    int ln = lock.size();
    
    // 자물쇠 안쪽에 자물쇠 정보를 넣음
    for (int i = 0 ; i < ln ; i++){
        for (int j = 0 ; j < ln ; j++){
            check_lock[i + ln - 1][j + ln - 1] = lock[i][j];
        }
    }
    
    // 회전을 총 4번 하면 돌아오므로
    for (int k = 0 ; k < 4 ; k++){
        // 회전
        rotate(key);
        // 자물쇠 시작점
        for (int lx = 0 ; lx < ln*2 + 1 ; lx++){
            for (int ly = 0 ; ly < ln*2 + 1 ; ly++){
                // 열쇠 시작점
                for (int kx = 0 ; kx < kn ; kx++){
                    for (int ky = 0 ; ky < kn ; ky++){
                        // 열쇠를 자물쇠에 넣음 (1이면 알맞게 들어간 것, 아니면 들어가지 않았거나 벽에 끼인 것)
                        check_lock[lx + kx][ly + ky] += key[kx][ky];
                    }
                }
                // 만일 정답이면 true 리턴
                if (check(check_lock, ln))
                    return true;
                // 정답이 아니라면 역산하여 제거
                for (int kx = 0 ; kx < kn ; kx++){
                    for (int ky = 0 ; ky < kn ; ky++){
                            check_lock[lx + kx][ly + ky] -= key[kx][ky];
                    }
                }
            }
        }
    }
    // 반복을 마쳐도 정답이 없다면 풀 수 없는 자
    return false;;
}
