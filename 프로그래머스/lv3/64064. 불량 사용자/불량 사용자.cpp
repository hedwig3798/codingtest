#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool check_same(string u, string b){
    if (u.length() != b.length())
        return false;
    for (int i = 0 ; i < u.length() ; i++){
        if (b[i] == '*')
            continue;
        if (b[i] != u[i])
            return false;
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<int> temp (user_id.size(), 1);
    for (int i = 0; i < banned_id.size() ; i++){
        temp[i] = 0;
    }
    
    do{
        vector<string> ts;
        for (int i = 0; i < temp.size() ; i++){
            if (temp[i] == 0){
                ts.push_back(user_id[i]);
            }
        }
        
        sort(ts.begin(), ts.end());
        
        do{
            int flag = 1;
            for (int i = 0; i < ts.size(); i++){
                if (! check_same(ts[i], banned_id[i])){
                    flag = 0;
                    break;
                }
            }
            if (flag == 1){
                answer++;
                break;
            }
        }while (next_permutation(ts.begin(), ts.end()));
        
        
    }while (next_permutation(temp.begin(), temp.end()));
    
    return answer;
}