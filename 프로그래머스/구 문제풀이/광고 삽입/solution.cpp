#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    // 정수 정답이 담길 변수
    long long s_answer = 0;
    // 주어진 시간을 전부 정수화
    long long s_play_time;
    long long s_adv_time;
    
    // 각 시간을 정수화
    s_play_time = stoi(play_time.substr(0, 2));
    s_play_time = s_play_time*60 + stoi(play_time.substr(3, 4));
    s_play_time = s_play_time*60 + stoi(play_time.substr(6, 7));
    
    s_adv_time = stoi(adv_time.substr(0, 2));
    s_adv_time = s_adv_time*60 + stoi(adv_time.substr(3, 4));
    s_adv_time = s_adv_time*60 + stoi(adv_time.substr(6, 7));
    
    // 누적합 배열 생성
    vector<long long> timeline(s_play_time+1, 0);
    for (auto i : logs){
        long long start;
        long long end;
        start = stoi(i.substr(0, 2));
        start = start*60 + stoi(i.substr(3, 4));
        start = start*60 + stoi(i.substr(6, 7));
        
        end = stoi(i.substr(9, 10));
        end = end*60 + stoi(i.substr(12, 13));
        end = end*60 + stoi(i.substr(15, 16));
        timeline[start] += 1;
        timeline[end] -= 1;
    }
    
    // 누적합 구하기
    for (long long i = 0 ; i < timeline.size() ; i++){
        timeline[i] += timeline[i-1];
    }
  
    // 구간합 구하기
    long long t = 0;
    for (long long i = 0 ; i < timeline.size() ; i++){
        t += timeline[i];
        timeline[i] = t;
    }
  
    // 0초 시작인 경우
    long long max_time = timeline[s_adv_time] - timeline[0];
    // 그 외 경우 1초씩 밀면서 구하기
    for (long long i = 1 ; i < timeline.size() ; i++){
        if (s_adv_time + i > s_play_time)
            break;
        if (max_time < timeline[i+s_adv_time] - timeline[i]){
            s_answer = i+1;
            max_time = timeline[i+s_adv_time] - timeline[i];
        }
    }
    
    // 정수 시간을 
    long long h = (s_answer / 60) / 60;
    long long m = s_answer / 60 - h*60;
    long long s = s_answer - (((h*60) + m) * 60);
    
    if (h < 10)
        answer += "0";
    answer += to_string(h) + ":";
    if (m < 10)
        answer += "0";
    answer += to_string(m) + ":";
    if (s< 10)
        answer += "0";
    answer += to_string(s);
    
    return answer;
}
