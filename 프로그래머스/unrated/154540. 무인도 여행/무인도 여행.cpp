#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;
bool is_visit[100][100] = {false, };
int get_w (vector<string> &maps, int i, int j){
    
    if (i < 0 || i >= maps.size() || j < 0 || j >= maps[0].size())
        return 0;
    
    if (maps[i][j] == 'X' || is_visit[i][j] == true)
        return 0;
    
    int result = maps[i][j] - '0';
    
    is_visit[i][j] = true;
    
    result += get_w(maps, i+1, j);
    result += get_w(maps, i-1, j);
    result += get_w(maps, i, j+1);
    result += get_w(maps, i, j-1);
    
    return result;
        
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for (int i = 0 ; i < maps.size() ; i++){
        for (int j = 0 ; j < maps[0].size() ; j++){

            if (maps[i][j] == 'X' || is_visit[i][j] == true)
                continue;
            answer.push_back(get_w(maps, i, j));
        }

    }
    if (answer.size() == 0)
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());
    return answer;
}