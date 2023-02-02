#include <bits/stdc++.h>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    // 정답 초기화
    string answer(n , 'O');
    // 되돌리기용 스텍
    stack<int*> undo;
    // 표
    int table[1000000][3];
    
    // 값을 표에 입력
    for (int i = 0 ; i < n ; i++){
        table[i][0] = i;
        table[i][1] = i-1;
        table[i][2] = i+1;
    }
    // 끝값 초기화
    table[n-1][2] = -1;
    
    // 현재 위치 지정
    int now = k;
    for (auto i : cmd){
        if (i[0] == 'U'){
            // 위로 올라가는 경우
            for (int j = 0 ; j < stoi(i.substr(2)) ; j++){
                now = table[now][1];
            }
        }
        else if (i[0] == 'D'){
            // 아래로 내려가는 경우
            for (int j = 0 ; j < stoi(i.substr(2)) ; j++){
                now = table[now][2];
            }
        }
        // 삭제하는 경우
        else if (i[0] == 'C'){
            // 되돌리기를 위해 스텍에 입력
            undo.push(table[now]);
            // 삭제 했으므로 표시
            answer[now] = 'X';
            
            // 만일 위값이 있는 경우
            if (table[now][1] != -1){
                table[table[now][1]][2] = table[now][2];
            }
            // 만일 아랫값이 있는 경우
            if (table[now][2] != -1){
                table[table[now][2]][1] = table[now][1];
                // 아랫값이 있으면 현재 위치를 아래로 내림
                now = table[now][2];
            }
            else {
                // 없으면 위로 올림
                now = table[now][1];
            }
            
                
        }
        else if (i[0] == 'Z'){
            // 되돌릴게 없으면 무시
            if (undo.empty())
                continue;
            // 있다면 값을 가져옴
            int* temp = undo.top();
            undo.pop();
            // 되돌렸으므로 정답에 표시
            answer[temp[0]] = 'O';
            // 만일 되돌린 값이 최상단 값이 아니면
            if (temp[1] != -1){
                table[temp[1]][2] = temp[0];
            }
            // 최하단 값이 
            if (temp[2] != -1){
                table[temp[2]][1] = temp[0];
            }
        }
    }

    return answer;
}
