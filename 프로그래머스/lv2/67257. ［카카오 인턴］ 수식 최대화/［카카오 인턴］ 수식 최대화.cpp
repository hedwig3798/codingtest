#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<string> midward(string exp){
    vector<string> result;
    int temp = 0;
    for (char i : exp){
        if (i >= '0' && i <= '9'){
            temp = temp*10 + i - '0';
        }
        else{
            result.push_back(to_string(temp));
            string s;
            s += i;
            result.push_back(s);
            temp = 0;
        }
    }
    result.push_back(to_string(temp));
    return result;
}

vector<string> backward(char t1, char t2, char t3, vector<string> mid){
    vector<string> result;
    string s1, s2, s3;
    s1 = t1;
    s2 = t2;
    s3 = t3;
    stack<string> c;
    for (int i = 0 ; i < mid.size() ; i++){
        if (mid[i] != s1 && mid[i] != s2 && mid[i] != s3)
            result.push_back(mid[i]);
        else if (c.empty())
            c.push(mid[i]);
        else if (mid[i] == s1 && (c.top() == s2 || c.top() == s3))
            c.push(mid[i]);
        else if (mid[i] == s2 && c.top() == s3)
            c.push(mid[i]);
        else {
            while(1){
                if (c.empty()){
                    c.push(mid[i]);
                    break;
                }
                else if (mid[i] == s1 && c.top() == s1){
                    result.push_back(c.top());
                    c.pop();
                }
                else if (mid[i] == s2 && (c.top() == s1 || c.top() == s2)){
                    result.push_back(c.top());
                    c.pop();
                }
                else if (mid[i] == s3){
                    result.push_back(c.top());
                    c.pop();
                }
                else {
                    c.push(mid[i]);
                    break;
                }
            }
        }
        
    }
    
    while (!c.empty()){
        result.push_back(c.top());
        c.pop();
    }
    return result;
}

long long calaulate(vector<string> back){
    stack<string> s;
    for (auto i : back){
        if (s.empty()){
            s.push(i);
        }
        else if (i != "*" && i != "+" && i != "-"){
            s.push(i);
        }
        else{
            long long num1 = stoll(s.top());
            s.pop();
            long long num2 = stoll(s.top());
            s.pop();
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
    
    char cal[3] = {'+', '-', '*'};
    vector<string> mid = midward(expression);
    
    for (auto t1 : cal){
        for (auto t2 : cal){
            if (t2 == t1)
                continue;
            for (auto t3 : cal){
                if (t3 == t1 || t3 == t2)
                    continue;

                vector<string> back = backward(t1, t2, t3, mid);
                

                
                long long temp = calaulate(back);

                
                if (temp < 0)
                    temp *= -1;
                answer = max(answer, temp);
            }
        }
    }
    
    return answer;
}