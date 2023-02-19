#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

// 숫자를 2진수 문자열로 바꾸는 함수
string binary(long long number){
    stack<int> s;
    for (;number > 0; number /= 2){
        s.push(number%2);
    }
    string result = "";
    for (;!s.empty();){
        result += s.top() + '0';
        s.pop();
    }
    return result;
}

// dp 함수
bool dp (string s) {
    // 말단이면 언제나 참 이므로 리턴
    if (s.length() == 1)
        return true;
    
    // 중앙값과 그 값을 기준으로 나눈 두 문자열
    char center = s[s.length()/2];
    string left = s.substr(0, s.length()/2);
    string right = s.substr(s.length()/2+1);
    // 만일 중앙값이 0 인경우
    if (center == '0'){
        char l_center = left[left.length()/2];
        char r_center = right[right.length()/2];
        // 양쪽의 문자열 중에 하나라도 1이 있는 경우 거짓
        if (l_center == '1' || r_center == '1')
            return false;
    }
    
    // 위 조건이 통과된 경우 남은 문자열에 대해 반복
    return dp(left) && dp(right);
        
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for (auto number : numbers){
        // 2진 문자열로 변환
        string s = binary(number);
        // 트리의 깊이
        int level = 0;
        // 트리의 깊이 구하기
        for (; s.length() > pow(2, level) - 1; level++){
            
        }
        // 총 트리의 길이 만큼 앞부분에 '0'추가
        // 문자열 앞에 아무리 '0'을 넣는다 하더라도 값은 변하지 않음
        for (int i = s.length() ; i < pow(2, level) - 1 ; i++){
            s = '0' + s;
        }
        
        // dp를 돌려서 결과 
        if (dp(s))
            answer.push_back(1);
        else
            answer.push_back(0);

    }
    
    return answer;
}
