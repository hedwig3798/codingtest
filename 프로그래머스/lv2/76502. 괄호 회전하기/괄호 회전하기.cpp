#include <string>
#include <vector>

using namespace std;

bool check(string s){
    vector<char> cc;
    for (char c : s){
        if (cc.empty())
            cc.push_back(c);
        else if (c == '[' || c == '{' || c == '(')
            cc.push_back(c);
        else if (cc.back() == '[' && c != ']')
            return false;
        else if (cc.back() == '{' && c != '}')
            return false;
        else if (cc.back() == '(' && c != ')')
            return false;
        else
            cc.pop_back();
    }
    if (cc.empty())
        return true;
    return false;

}

string rotate(string s){
    string first = s.substr(0,1);
    string sub = s.substr(1, s.length() - 1);
    s = sub + first;
    return s;
}

int solution(string s) {
    int answer = 0;
    
    for (int i = 0 ; i < s.length() ; i++){
        if (check(s))
            answer++;
        s = rotate(s);
    }
    
    return answer;
}