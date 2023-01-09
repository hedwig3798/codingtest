#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    // 누적합을 저장 할 벡터
    vector<vector<int>> p_sum (board.size()+1, vector<int>(board[0].size()+1, 0));
    
    // 모든 스킬에 대하여 누적함 저장
    for (auto s : skill){
        // 제한사항에 맞도록 수치 구하기
        int type = 1;
        int dgree = 0;
        if (s[0] == 1){
            type = -1;
        }
        dgree = s[5] * type;
        
        // 누적합 배열에 값 넣기
        p_sum[s[1]][s[2]] += dgree;
        p_sum[s[1]][s[4]+1] -= dgree;
        p_sum[s[3]+1][s[2]] -= dgree;
        p_sum[s[3]+1][s[4]+1] += dgree;

    }
    

    // 누적합 구하기 (우 -> 좌)
    for (int i = 0 ; i < p_sum.size() ; i++){
        for (int j = 1 ; j < p_sum[0].size() ; j++){
            p_sum[i][j] += p_sum[i][j-1];
        }
    }
    // 누적합 구하기 (상 -> 하)
    for (int i = 0 ; i < p_sum[0].size() ; i++){
        for (int j = 1 ; j < p_sum.size() ; j++){
            p_sum[j][i] += p_sum[j-1][i];
        }
    }
    
    // 구한 누적값을 주어진 board에 더하면서 조건에 맞는 값 
    for (int i = 0 ; i < board.size() ; i++){
        for (int j = 0 ; j < board[0].size() ; j++){
            if (board[i][j] + p_sum[i][j] > 0){
                answer++;
            }
        }
    }
    
    
    return answer;
}
