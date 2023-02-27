#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer (numbers.size());
    stack<pair<int, int>> s;
    
    for (int i = 0 ; i < numbers.size() ; i++){
        if (s.empty()){
            s.push({i, numbers[i]});
        }
        else {
            for (;!s.empty() && s.top().second < numbers[i];){
                auto temp = s.top();
                s.pop();
                answer[temp.first] = numbers[i];
            }
            s.push({i, numbers[i]});
        }
    }
    
    for (;!s.empty();){
        auto temp = s.top();
        s.pop();
        answer[temp.first] = -1;
    }
    
    
    return answer;
}