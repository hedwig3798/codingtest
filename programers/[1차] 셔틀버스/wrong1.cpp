#include <bits/stdc++.h>
#include<cstdlib>
using namespace std;

bool time_comp(string a, string b){
    int ha = stoi(a.substr(0, 2));
    int hb = stoi(b.substr(0, 2));
    
    int ma = stoi(a.substr(3, 4));
    int mb = stoi(b.substr(3, 4));
    if (ha > hb)
        return false;
    else if (ha < hb)
        return true;
    
    if (ma > mb)
        return false;
    else if (ma < mb)
        return true;
    
    return true;
}

string time_plus(string now, int puls){
    int hour = stoi(now.substr(0, 2));
    int min = stoi(now.substr(3, 4));
    
    min += puls;
    
    if (min >= 60){
        min -= 60;
        hour += 1;
    }
    else if (min < 0){
        min += 60;
        hour -= 1;
    }
    
    string sh = to_string(hour);
    string sm = to_string(min);
    
    if (hour < 10)
        sh = "0"+sh;
    if (min < 10)
        sm = "0"+sm;
    
    return sh + ":" + sm;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    sort(timetable.begin(), timetable.end(), time_comp);

    stack<string> bus;
    int count = 0;
    string now_time = "09:00";
    string fm = "";
    int ind;
    for (;ind < timetable.size();){
        if (bus.size() == m){
            bus = stack<string>();
            count++;
            now_time = time_plus(now_time, t);
        }
        
        if (time_comp(timetable[ind], now_time)){
            bus.push(timetable[ind]);
            ind++;
        }
        else {
            bus = stack<string>();
            count++;
            now_time = time_plus(now_time, t);
        }
        if (count == n){
            break;
        }
    }
    
    if (bus.size() == m){
        answer = time_plus(bus.top(), -1);
    }
    else {
        answer = time_plus(now_time, -1*t);
        if (time_comp(answer, "09:00"))
            answer = "09:00";
    }
    
    return answer;
}
