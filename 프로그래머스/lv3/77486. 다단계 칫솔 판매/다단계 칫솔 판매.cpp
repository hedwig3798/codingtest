#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer (enroll.size());
    map<string, int> result;
    map<string, string> tree;

    
    for (int i = 0 ; i < enroll.size() ; i++){
        tree[enroll[i]] = referral[i];
        result[enroll[i]] = 0;
    }
    
    // for (int i = 0 ; i < enroll.size() ; i++){
    //     cout << tree[enroll[i]] << endl;
    // }
    
    for (int i = 0 ; i < seller.size() ; i++){
        string sell = seller[i];
        int mount = amount[i] * 100;
        
        for (;mount > 0 && sell != "-";){
            //cout << sell << ' ' << mount << endl;
            result[sell] += mount - mount/10;
            mount /= 10;
            sell = tree[sell];
        }
    }
    
    for (int i = 0 ; i < enroll.size() ; i++){
        answer[i] = result[enroll[i]];
    }
    
    return answer;
}