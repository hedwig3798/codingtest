#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

int solution(vector<string> board) {

    int count_o = 0;
    int count_x = 0;
    
    bool win_o = false;
    bool win_x = false;
    
    for (auto i : board){
        for (auto j : i){
            if (j == 'O')
                count_o++;
            else if (j == 'X')
                count_x++;
        }
    }
    
    for (int i = 0 ; i < 3 ; i++){
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            if (board[i][0] == 'O')
                win_o = true;
            else if (board[i][0] == 'X')
                win_x = true;
        }
        
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            if (board[0][i] == 'O')
                win_o = true;
            else if (board[0][i] == 'X')
                win_x = true;
        }
    }
    
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        if (board[0][0] == 'O')
            win_o = true;
        else if (board[0][0] == 'X')
            win_x = true;
    }
    
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2]){
        if (board[2][0] == 'O')
            win_o = true;
        else if (board[2][0] == 'X')
            win_x = true;
    }
    
    if (count_x > count_o)
        return 0;
    if (count_o - count_x > 1)
        return 0;
    if (win_x && win_o)
        return 0;
    if (win_x && count_o != count_x)
        return 0;
    if (win_o && count_o != count_x+1)
        return 0;
    
    return 1;
}