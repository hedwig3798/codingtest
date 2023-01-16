#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// 2진변환값을 문자열로 보내는 함수
string bin(int len){
    string result = "";
    for ( ; len != 0; ){
        result += to_string(len%2);
        len /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    int zero = 0;
    int cir = 0;
    // 주어진 s 의 길이가 1이 될 
    for (;s.length() != 1;){
        cir++;
        int count = 0;
        for (char c : s){
            if (c == '0'){
                count++;
                zero++;
            }
        }
        
        s = bin(s.length() - count);
    }
    answer.push_back(cir);
    answer.push_back(zero);
    return answer;
}
