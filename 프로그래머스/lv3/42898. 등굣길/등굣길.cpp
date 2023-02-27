#include <string>
#include <vector>
#include <iostream>
using namespace std;
void dp (vector<vector<int>> &board, int x, int y, int m, int n){
    //cout << x << ' ' << y << ' ' << m << ' ' << n << endl;
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
    
    vector<vector<int>> board (n+1, vector<int>(m+1, 0));
    
    for (auto i : puddles){
        board[i[1]][i[0]] = -1;
    }
    
    // dp (board, 0, 0, m, n);
    if (board[1][2] != -1)
        board[1][2] = 1;
    if (board[2][1] != -1)
        board[2][1] = 1;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= m ; j++){
            if (board[i][j] == -1)
                continue;
            
            if (board[i-1][j] != -1)
                board[i][j] = (board[i][j] + board[i-1][j]) % 1000000007;
            if (board[i][j-1] != -1)
                board[i][j] = (board[i][j] + board[i][j-1]) % 1000000007;
        }
    }
    
    // cout << endl;
    // for (auto i : board){
    //     for (auto j : i){
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
    
    return board[n][m];
}