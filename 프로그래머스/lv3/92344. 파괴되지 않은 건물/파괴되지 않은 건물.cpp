#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    vector<vector<int>> p_sum (board.size()+1, vector<int>(board[0].size()+1, 0));

    for (auto s : skill){
        
        int type = 1;
        int dgree = 0;
        if (s[0] == 1){
            type = -1;
        }
        
        dgree = s[5] * type;
        
        p_sum[s[1]][s[2]] += dgree;
        p_sum[s[1]][s[4]+1] -= dgree;
        p_sum[s[3]+1][s[2]] -= dgree;
        p_sum[s[3]+1][s[4]+1] += dgree;

    }
    

    
    for (int i = 0 ; i < p_sum.size() ; i++){
        for (int j = 1 ; j < p_sum[0].size() ; j++){
            p_sum[i][j] += p_sum[i][j-1];
        }
    }
    
    for (int i = 0 ; i < p_sum[0].size() ; i++){
        for (int j = 1 ; j < p_sum.size() ; j++){
            p_sum[j][i] += p_sum[j-1][i];
        }
    }
    
    
    for (int i = 0 ; i < board.size() ; i++){
        for (int j = 0 ; j < board[0].size() ; j++){
            if (board[i][j] + p_sum[i][j] > 0){
                answer++;
            }
        }
    }
    
    
    return answer;
}