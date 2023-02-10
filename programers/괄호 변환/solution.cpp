#include <bits/stdc++.h>

using namespace std;
// 괄호 문자열을 두 균형 문자열로 분리
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

// 올바른 괄호 문자열인지 체크
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
    
    // 만일 입력이 비어있다면 리턴
    if (p == answer)
        return answer;
    
    // 입력 받은 문자열을 균형 괄호 문자열 2개로 나눔
    pair<string, string> d;
    d = devision(p);
  
    // 만일 첫 문자열이 올바른 문자열 이라면
    if (check_right(d.first)){
        // 첫 문자열에 2번째 문자열을 재귀시켜 더함
        answer += d.first;
        answer += solution(d.second);
    }
    // 아니라면
    else {
        // 제한조건에 맞도록 수행
        answer += "(";
        answer += solution(d.second);
        answer += ")";
        string u = d.first.substr(1, d.first.length()-2);
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
