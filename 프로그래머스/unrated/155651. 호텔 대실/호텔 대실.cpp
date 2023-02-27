#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    int timeline[23*60 + 59 + 10] = {0, };
    for (auto time : book_time){
        int start = 0;
        int end = 0;
        
        start += stoi(time[0].substr(0, 2)) * 60;
        start += stoi(time[0].substr(3, 4));
        
        end += stoi(time[1].substr(0, 2)) * 60;
        end += stoi(time[1].substr(3, 4));
        
        timeline[start] += 1;
        timeline[end + 10] -= 1;
    }
    
    for (int i = 1 ; i < 23*60 + 59 + 10 ; i++){
        timeline[i] += timeline[i-1];
        answer = max(answer, timeline[i]);
    }
    
    return answer;
}