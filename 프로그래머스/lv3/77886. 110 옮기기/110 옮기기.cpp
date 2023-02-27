#include <bits/stdc++.h>

using namespace std;


vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for (auto ss : s){
        stack <char> sstack;
        int count = 0;
        for (int i = 0 ; i < ss.length() ; i++){
            sstack.push(ss[i]);
            if (sstack.size() >= 3){
                char thi = sstack.top();
                sstack.pop();
                char sec = sstack.top();
                sstack.pop();
                char fir = sstack.top();
                sstack.pop();
                
                if (fir == '1' && sec == '1' && thi == '0'){
                    count++;
                }
                else {
                    sstack.push(fir);
                    sstack.push(sec);
                    sstack.push(thi);
                }
            }
        }
        
        // for (;!sstack.empty();){
        //     cout << sstack.top();
        //     sstack.pop();
        // }
        // cout << endl;
        
        if (count == 0){
            answer.push_back(ss);
            continue;
        }
        
        int ind = sstack.size();
        string temp = "";
        for (;!sstack.empty() && sstack.top() == '1';){
            ind--;
            temp = sstack.top() + temp;
            sstack.pop();
        }
        
        for (;!sstack.empty();){
            temp = sstack.top() + temp;
            sstack.pop();
        }
        //cout << temp << endl;
        for (;count > 0 ; count -= 1){
            temp.insert(ind, "110");
        }
        
        answer.push_back(temp);
    }
    
    
    return answer;
}