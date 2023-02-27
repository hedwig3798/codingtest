#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

int solution(string s) {
    int answer = INF;

    for (int i = 1 ; i < s.length()/2 + 2 ; i++){
        int count = i;
        string old = s.substr(0, i);
        int flag = 0;
        for(int j = i ; j < s.length() ; j += i){
            string now = s.substr(j, i);
            if (old == now){
                flag++;
                continue;
            }
            if (flag != 0){
                flag++;
            }
            
            for ( ; flag > 0 ; ){
                count++;
                flag = flag/10;
            }
            
            count += now.length();
            old = now;
            flag = 0;
        }
        
        if (flag != 0){
            flag++;
        }
        for ( ; flag > 0 ; ){
            count++;
            flag = flag/10;
        }
        
        answer = min(answer, count);
    }
    return answer;
}