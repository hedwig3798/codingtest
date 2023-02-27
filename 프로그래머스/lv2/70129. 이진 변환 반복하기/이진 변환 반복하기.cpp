#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

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