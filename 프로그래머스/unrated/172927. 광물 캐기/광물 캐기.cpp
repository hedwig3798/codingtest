#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    int limits = (picks[0] + picks[1] + picks[2]) * 5;
    limits = min((int)minerals.size(), limits);
    
    vector<vector<int>> cost;
    

    for (int i = 0 ; i < limits ; i += 5){
        vector<int> temp (3, 0);
        int ind = 5;
        if (i + 5 >= limits){
            ind = limits - i;
        }

        for (int j = i ; j < i + ind ; j++){
            if (minerals[j] == "diamond")
                temp[0]++;
            else if (minerals[j] == "iron")
                temp[1]++;
            else if (minerals[j] == "stone")
                temp[2]++;
        }
        cost.push_back(temp);
        
    }
    
    sort(cost.begin(), cost.end(), greater<vector<int>>());
    
    for (auto c : cost){
        if (picks[0] > 0) {
            picks[0]--;
            answer += c[0] + c[1] + c[2];;
            continue;
        }
        if (picks[1] > 0){
            picks[1]--;
            answer += c[0]*5 + c[1] + c[2];
            continue;
        }
        if (picks[2] > 0){
            picks[2]--;
            answer += c[0]*25 + c[1]*5 + c[2];
            continue;
        }
    }
    
    return answer;
}