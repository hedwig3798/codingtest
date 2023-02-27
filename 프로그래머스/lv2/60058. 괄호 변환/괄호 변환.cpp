#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

pair<string, string> devision(string p){
    int open = 0;
    int close = 0;
    
    for (int i = 0 ; i < p.length() ; i++){
        if (p[i] == '(')
            open++;
        else
            close++;
        
        if (open == close){
            return {p.substr(0, i+1), p.substr(i+1, p.length())};
        }
    }
}

bool check_right(string p){
    stack<char> s;
    
    for (auto i : p){
        if (s.empty() && i == ')')
            return false;
        
        if (i == '(')
            s.push(i);
        else
            s.pop();
    }
    return true;
}

string solution(string p) {
    string answer = "";
    
    if (p == answer)
        return answer;
    
    pair<string, string> d;
    
    d = devision(p);
    if (check_right(d.first)){
        answer += d.first;
        answer += solution(d.second);
    }
    else {
        answer += "(";
        answer += solution(d.second);
        answer += ")";
        string u = d.first.substr(1, d.first.length()-2);
        //cout << d.first << ' ' << u << endl;
        for (auto i : u){
            if (i == '(')
                answer += ")";
            else{
                answer+= "(";
            }
        }
    }
    

    
    return answer;
}