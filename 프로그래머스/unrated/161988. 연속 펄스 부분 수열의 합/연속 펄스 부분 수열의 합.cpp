#include <bits/stdc++.h>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    vector<long long> p1;
    vector<long long> p2;
    
    long long ind = 1;
    
    for (auto i : sequence){
        p1.push_back((long long)i * ind);
        p2.push_back((long long)i * ind * -1);
        ind *= -1;
    }
    
    
    for (int i = 1 ; i < p1.size() ; i++){
        p1[i] = max(p1[i], p1[i] + p1[i-1]);
        p2[i] = max(p2[i], p2[i] + p2[i-1]);
    }
    
    return max(*max_element(p1.begin(), p1.end()), *max_element(p2.begin(), p2.end()));
}