#include <bits/stdc++.h>

using namespace std;

// string 시간 정보를 int형으로 변경 (단위 : 분)
int ttoi (string s){
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 4));
    
    return h*60 + m;
}

// int형 시간 정보를 string으로 바꿈
string itot(int i){
    int h = i/60;
    int m = i%60;
    
    string sh = to_string(h);
    string sm = to_string(m);
    
    if (h < 10)
        sh = "0" + sh;
    if (m < 10)
        sm = "0" + sm;
    
    return sh + ":" + sm;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    // 분 단위로 변경된 시간 벡터
    vector<int> itime;
    // 값을 넣음
    for (auto i : timetable){
        itime.push_back(ttoi(i));
    }
    
    // 오름차순 정렬
    sort(itime.begin(), itime.end());
    
    // 초기값 설정
    // 현재 시간 (540분)
    int now_time = 9*60;
    // 시간표를 참조할 인덱스
    int ind = 0;
    // 만차인지 아닌지
    bool full = false;
  
    // 모든 버스에 대하여 순회
    for (int i = 0 ; i < n ; i++){
        // 유지될 시 만차임
        full = true;
        // 모든 크류에 대하여 지금 버스를 탈 수 있는지 없는지 확인
        for (int j = 0 ; j < m ; j++){
            // 인덱스가 초과되는 경우
            if (ind >= itime.size()){
                full = false;
                break;
            }
            // 탈 수 있는 경우
            if (itime[ind] <= now_time)
                ind++;
            // 탈 수 없는 경우
            else {
                full = false;
                break;
            }
        }
        // 다음 차량 진입
        now_time += t;
    }
  
    // 막차가 만차인 경우 마지막 사람 보다 1분 일찍 오면 된다.
    if (full){
        answer = itot(itime[ind-1] - 1); 
    }
    // 아닌경우 만차 시간에 오면 된다.
    else{
        answer = itot(now_time - t);
    }
    
    return answer;
}
