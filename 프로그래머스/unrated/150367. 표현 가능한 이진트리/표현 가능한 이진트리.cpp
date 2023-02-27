#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

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

bool dp (string s) {
    if (s.length() == 1)
        return true;
    
    char center = s[s.length()/2];
    string left = s.substr(0, s.length()/2);
    string right = s.substr(s.length()/2+1);
    //cout << left << ' ' << right << endl;
    if (center == '0'){
        char l_center = left[left.length()/2];
        char r_center = right[right.length()/2];
        if (l_center == '1' || r_center == '1')
            return false;
    }
    
    return dp(left) && dp(right);
        
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for (auto number : numbers){
        string s = binary(number);
        int level = 0;
        for (; s.length() > pow(2, level) - 1; level++){
            
        }
        for (int i = s.length() ; i < pow(2, level) - 1 ; i++){
            s = '0' + s;
        }
        //cout << s << endl;
        if (dp(s))
            answer.push_back(1);
        else
            answer.push_back(0);

    }
    
    return answer;
}