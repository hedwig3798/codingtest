#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

// 문자열을 벡터 형식의 중위 식으로 변경하는  함수
vector<string> midward(string exp){
    vector<string> result;
    int temp = 0;
    for (char i : exp){
        // 숫자의 경우 정수로 바꿈 (제한사항에 따라 int형 변수 사용 가는함)
        if (i >= '0' && i <= '9'){
            temp = temp*10 + i - '0';
        }
        // 연산자의 경우 숫자와 함께 벡터에 입력
        else{
            result.push_back(to_string(temp));
            string s;
            s += i;
            result.push_back(s);
            temp = 0;
        }
    }
    // 중위 표기식은 무조건 숫자로 끝나므로 마지막 숫자를 입력
    result.push_back(to_string(temp));
    return result;
}

// 벡터 형식의 중위 표기식을 후위 표기식으로 변경 (t1 > t2 > t3 의 우선순위)
vector<string> backward(char t1, char t2, char t3, vector<string> mid){
    vector<string> result;
    // string형식으로 연산자 바꿈
    string s1, s2, s3;
    s1 = t1;
    s2 = t2;
    s3 = t3;
    stack<string> c;
    // 변경 알고리즘
    for (int i = 0 ; i < mid.size() ; i++){
        // 숫자의 경우 바로 벡터에 넣음
        if (mid[i] != s1 && mid[i] != s2 && mid[i] != s3)
            result.push_back(mid[i]);
        // 연산자 스택이 비어있으면 바로 넣음
        else if (c.empty())
            c.push(mid[i]);
        // 우선순위에 따라 스텍에 연산자를 바로 넣음
        else if (mid[i] == s1 && (c.top() == s2 || c.top() == s3))
            c.push(mid[i]);
        else if (mid[i] == s2 && c.top() == s3)
            c.push(mid[i]);
        // 스텍에서 연산자를 뺴야 할 때
        else {
            // 조건에 맞을 떄 까지
            while(1){
                // 스텍이 비어있으면 지금 연산자를 넣고 종료
                if (c.empty()){
                    c.push(mid[i]);
                    break;
                }
                // 우선순위가 가장 높은 연산자의 경우
                else if (mid[i] == s1 && c.top() == s1){
                    result.push_back(c.top());
                    c.pop();
                }
                // 우선순위가 중간인 연산자의 경우
                else if (mid[i] == s2 && (c.top() == s1 || c.top() == s2)){
                    result.push_back(c.top());
                    c.pop();
                }
                // 우선순위가 가장 낮은 연산자의 경우
                else if (mid[i] == s3){
                    result.push_back(c.top());
                    c.pop();
                }
                // 그 외 경우
                else {
                    c.push(mid[i]);
                    break;
                }
            }
        }
        
    }
    // 스텍에 남은 연산자를 입력
    while (!c.empty()){
        result.push_back(c.top());
        c.pop();
    }
    return result;
}

// 후위 연산 계산 함수
long long calaulate(vector<string> back){
    stack<string> s;
    // 후위 연산 값을 하나씩 가져오면서 계산
    for (auto i : back){
        // 비어있다면 값을 넣음 (최초 1회)
        if (s.empty()){
            s.push(i);
        }
        // 숫자의 경우 스텍에 바로 넣음
        else if (i != "*" && i != "+" && i != "-"){
            s.push(i);
        }
        // 연산자의 종류에 따라 계산하여 넣음
        else{
            // 숫자 2개를 가져옴
            long long num1 = stoll(s.top());
            s.pop();
            long long num2 = stoll(s.top());
            s.pop();
            // 연산자에 따라 계산 후 입력
            if (i == "*")
                s.push(to_string(num1 * num2));
            else if (i == "+")
                s.push(to_string(num1 + num2));
            else if (i == "-")
                s.push(to_string(num2 - num1));
        }
    }
    return stoll(s.top());
}

long long solution(string expression) {
    long long answer = 0;
    // 연산자 목록
    char cal[3] = {'+', '-', '*'};
  
    // 문자열인 식을 벡터화
    vector<string> mid = midward(expression);
    
    // 가능한 모든 우선순위 조건 탐색 (같은 경우 제외)
    for (auto t1 : cal){
        for (auto t2 : cal){
            if (t2 == t1)
                continue;
            for (auto t3 : cal){
                if (t3 == t1 || t3 == t2)
                    continue;
                // 후위 연산자로 바꿈
                vector<string> back = backward(t1, t2, t3, mid);
                // 계산
                long long temp = calaulate(back);
                // 절댓값 변환
                if (temp < 0)
                    temp *= -1;
                // 최댓값 
                answer = max(answer, temp);
            }
        }
    }
    
    return answer;
}
