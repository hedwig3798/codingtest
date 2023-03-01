#include <string>
#include <vector>

using namespace std;

// 후위 표기법으로 변환 가능 한지
bool check(string s){
    vector<char> cc;
    for (char c : s){
        if (cc.empty())
            // 비어있는 경우
            cc.push_back(c);
        // 여는 괄호가 들어오는 경우 무조건 넣어도 상관이 없으므로
        else if (c == '[' || c == '{' || c == '(')
            cc.push_back(c);
        // 닫는 괄호가 들어 왔는데 짝이 맞지 않는 경우.
        // 괄호 외에 연산자가 없으므로 무조건 짝이 맞아야됨
        else if (cc.back() == '[' && c != ']')
            return false;
        else if (cc.back() == '{' && c != '}')
            return false;
        else if (cc.back() == '(' && c != ')')
            return false;
        // 짝이 맞는 경우 괄호를 벡터에서 제외
        else
            cc.pop_back();
    }
    // 벡터에 아무것도 없다면 모두 짝이 맞아 나간것
    if (cc.empty())
        return true;
    // 벡터에 무언가 남아 있다면 짝이 맞지 않는것
    return false;

}

// 문자열 회전 함수
string rotate(string s){
    // 첫 글자를 가져옴
    string first = s.substr(0,1);
    // 그 외 나머지를 가져옴
    string sub = s.substr(1, s.length() - 1);
    // 순서를 바꿔 더하면 회전 완료
    s = sub + first;
    return s;
}

int solution(string s) {
    int answer = 0;
    // 문자열 길이 만큼 
    for (int i = 0 ; i < s.length() ; i++){
        if (check(s))
            answer++;
        s = rotate(s);
    }
    
    return answer;
}
