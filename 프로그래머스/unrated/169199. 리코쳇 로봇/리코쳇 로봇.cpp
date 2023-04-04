#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> board) {
    int answer = 0;
    
    pair<int, int> startPoint;
    pair<int, int> goal;
    
    for (int i = 0 ; i < board.size() ; i++){
        for (int j = 0 ; j < board[0].size() ; j++){
            if (board[i][j] == 'R')
                startPoint = {i,j};
            else if(board[i][j] == 'G'){
                goal = {i,j};
            }
        }
    }
    int x[] = {0, 1, 0, -1};
    int y[] = {1, 0, -1, 0};
    
    vector<vector<int>> isVisit(board.size(), vector<int> (board[0].size(), -1));
    queue<pair<int, int>> q;
    q.push(startPoint);
    isVisit[startPoint.first][startPoint.second] = 0;
    for (;!q.empty();){
        pair<int, int>now =  q.front();
        q.pop();
        
        for (int i = 0 ; i < 4 ; i++){
            int nowx = now.first;
            int nowy = now.second;
            
            for (;;){
                nowx = nowx + x[i];
                nowy = nowy + y[i];
                
                if (nowx < 0 || nowx > board.size()-1 || nowy < 0 || nowy > board[0].size()-1 || board[nowx][nowy] == 'D'){
                    if (isVisit[nowx - x[i]][nowy - y[i]] == -1){
                        isVisit[nowx - x[i]][nowy - y[i]] = isVisit[now.first][now.second] + 1;
                        q.push({nowx - x[i], nowy - y[i]});
                    }
                    break;
                }
            }
        }
    }
    
    return isVisit[goal.first][goal.second];
}