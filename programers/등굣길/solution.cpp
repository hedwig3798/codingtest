#include <string>
#include <vector>
#include <iostream>
using namespace std;

// dp 함수 실제 풀이에는 사용하지 않았다.
// 함수로 재사용 할 경우 범위 조절 필요
void dp (vector<vector<int>> &board, int x, int y, int m, int n){

    if ((x == m-1 && y == n-1) || (x == m-1 && y == n-1)){
        return;
    }
    if (x+1 < m && board[y][x+1] != -1){
        dp(board, x+1, y, m, n);
        board[y][x+1] = (board[y][x+1]+1) % 1000000007;
    }
    if (y+1 < n && board[y+1][x] != -1){
        dp(board, x, y+1, m, n);
        board[y+1][x] = (board[y+1][x]+1) % 1000000007;
    }
        
}

int solution(int m, int n, vector<vector<int>> puddles) {
    
    // 보드 가시화. 웅덩이가 있는 부분은 -1 아닌경우 0으로 채워넣음
    vector<vector<int>> board (n+1, vector<int>(m+1, 0));
    for (auto i : puddles){
        board[i[1]][i[0]] = -1;
    }
    
    // dp (board, 0, 0, m, n);
  
    // 집에서 가장 가까운 2곳을 1로 초기화 단, 웅덩이로 막혀 있는지 검사
    if (board[1][2] != -1)
        board[1][2] = 1;
    if (board[2][1] != -1)
        board[2][1] = 1;
    // dp 반복문
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= m ; j++){
            // 웅덩이인 경우 패스
            if (board[i][j] == -1)
                continue;
            // 좌측이 웅동이가 아닌 경우 최단 경로 가짓수 더함
            if (board[i-1][j] != -1)
                board[i][j] = (board[i][j] + board[i-1][j]) % 1000000007;
            // 위쪽이 웅덩이가 아닌 경우 최단 경로 가짓수 더함
            if (board[i][j-1] != -1)
                board[i][j] = (board[i][j] + board[i][j-1]) % 1000000007;
        }
    }
    // 최종적으로 경로의 가짓수를 
    return board[n][m];
}
