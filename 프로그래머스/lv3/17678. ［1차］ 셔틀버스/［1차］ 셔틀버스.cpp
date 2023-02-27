#include <bits/stdc++.h>

using namespace std;

int ttoi (string s){
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 4));
    
    return h*60 + m;
}

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
    vector<int> itime;
    
    for (auto i : timetable){
        itime.push_back(ttoi(i));
    }
    
    sort(itime.begin(), itime.end());
    
    int now_time = 9*60;
    int ind = 0;
    bool full = false;
    for (int i = 0 ; i < n ; i++){
        full = true;
        for (int j = 0 ; j < m ; j++){
            if (ind >= itime.size()){
                full = false;
                break;
            }
            if (itime[ind] <= now_time)
                ind++;
            else {
                full = false;
                break;
            }
        }
        now_time += t;
    }
    if (full){
        answer = itot(itime[ind-1] - 1); 

    }
    else{
        answer = itot(now_time - t);
    }
    
    return answer;
}