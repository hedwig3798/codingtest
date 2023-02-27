#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

int bfs(pair<int, int> start, vector<string> &maps, char flag){
    int result = 0;
    int is_visit[101][101] = {0, };
    
    queue<pair<int, int>> q;
    q.push(start);
    is_visit[start.first][start.second] = 1;
    
    for (;!q.empty();){
        pair<int, int> now = q.front();
        q.pop();
        //cout << now.first << ' ' << now.second << endl;
        if (maps[now.first][now.second] == flag){
            result = is_visit[now.first][now.second];
            return result;
        }
        else {
            if (now.first > 0){
                if (maps[now.first-1][now.second] != 'X' && is_visit[now.first-1][now.second] == 0){
                    q.push({now.first-1, now.second});
                    is_visit[now.first-1][now.second] = is_visit[now.first][now.second]+1;
                }
            }
            if (now.first < maps.size()-1){
                if (maps[now.first+1][now.second] != 'X' && is_visit[now.first+1][now.second] == 0){
                    q.push({now.first+1, now.second});
                    is_visit[now.first+1][now.second] = is_visit[now.first][now.second]+1;
                }
            }
            if (now.second > 0){
                if (maps[now.first][now.second-1] != 'X' && is_visit[now.first][now.second-1] == 0){
                    q.push({now.first, now.second-1});
                    is_visit[now.first][now.second-1] = is_visit[now.first][now.second]+1;
                }
            }
            if (now.second < maps[0].size()-1){
                if (maps[now.first][now.second+1] != 'X' && is_visit[now.first][now.second+1] == 0){
                    q.push({now.first, now.second+1});
                    is_visit[now.first][now.second+1] = is_visit[now.first][now.second]+1;
                }
            }
        }
    }
    return result;
}

int solution(vector<string> maps) {
    int answer = -1;
    pair<int, int> start;
    pair<int, int> end;
    pair<int, int> lever;
    
    for (int i = 0 ; i < maps.size() ; i++){
        for (int j = 0 ; j < maps[0].size() ; j++){
            if (maps[i][j] == 'S')
                start = {i, j};
            else if (maps[i][j] == 'E')
                end = {i, j};
            else if (maps[i][j] == 'L')
                lever = {i, j};
        }
    }
    // cout << start.first << ' ' << start.second << endl;
    // cout << end.first << ' ' << end.second << endl;
    // cout << lever.first << ' ' << lever.second << endl;
    int stol = bfs(start, maps, 'L');
    int ltoe = bfs(lever, maps, 'E');
    
    if (stol == 0 || ltoe == 0)
        return -1;
    
    answer = stol + ltoe - 2;

    
    return answer;
}