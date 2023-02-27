#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;

    for (int i = 1 ; i < cookie.size() ; i++){
        int second_ind = i;
        int first_ind = i-1;
        
        int second_sum = cookie[second_ind];
        int first_sum = cookie[first_ind];
        
        for (;;){
            if (second_sum == first_sum){
                answer = max(answer, second_sum);
            }
            
            if (first_sum <= second_sum){
                if (first_ind == 0)
                    break;
                else {
                    first_ind--;
                    first_sum += cookie[first_ind];
                }
            }
            else {
                if (second_ind == cookie.size()-1){
                    break;
                }
                else {
                    second_ind++;
                    second_sum += cookie[second_ind];
                }
            }
        }

    }
    
    return answer;
}