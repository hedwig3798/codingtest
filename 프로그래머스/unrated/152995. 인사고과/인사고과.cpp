#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] > b[0];
}

int solution(vector<vector<int>> scores) {
    int answer = 0;
    pair<int, int> wanho = {scores[0][0], scores[0][1]};
    int wanho_s = wanho.first + wanho.second;
    
    sort(scores.begin(), scores.end(), cmp);
    
    int min_score = 0;
    for (auto i : scores){
        //cout << i[0] << ' ' << i[1] << endl;
        if (i[1] < min_score){
            if (i[0] == wanho.first && i[1] == wanho.second)
                return -1;
            continue;
        }
        else {
            min_score = i[1];
            if (i[0] + i[1] > wanho_s)
                answer++;
        }
    }
    
    
    return answer+1;
}