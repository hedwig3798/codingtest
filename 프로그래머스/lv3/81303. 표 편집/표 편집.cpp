#include <bits/stdc++.h>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer(n , 'O');
    stack<int*> undo;
    int table[1000000][3];
    
    for (int i = 0 ; i < n ; i++){
        table[i][0] = i;
        table[i][1] = i-1;
        table[i][2] = i+1;
    }
    table[n-1][2] = -1;
    
    int now = k;
    for (auto i : cmd){
        if (i[0] == 'U'){
            for (int j = 0 ; j < stoi(i.substr(2)) ; j++){
                now = table[now][1];
            }
        }
        else if (i[0] == 'D'){
            for (int j = 0 ; j < stoi(i.substr(2)) ; j++){
                now = table[now][2];
            }
        }
        else if (i[0] == 'C'){
            undo.push(table[now]);
            answer[now] = 'X';
            
            if (table[now][1] != -1){
                table[table[now][1]][2] = table[now][2];
            }
            if (table[now][2] != -1){
                table[table[now][2]][1] = table[now][1];
                now = table[now][2];
            }
            else {
                now = table[now][1];
            }
            
                
        }
        else if (i[0] == 'Z'){
            if (undo.empty())
                continue;
            int* temp = undo.top();
            undo.pop();
            answer[temp[0]] = 'O';
            if (temp[1] != -1){
                table[temp[1]][2] = temp[0];
            }
            if (temp[2] != -1){
                table[temp[2]][1] = temp[0];
            }
        }
    }

    return answer;
}