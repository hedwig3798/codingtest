#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<long long, vector<long long>, less<long long>> pq;
    
    for (auto i : works){
        pq.push((long long)i);
    }
    
    for (int i = 0 ; i < n ; i++){
        long long temp = pq.top();
        if (pq.top() == 0){
            return 0;
        }
        pq.pop();
        pq.push(temp-1);
    }
    
    for (;!pq.empty();){
        answer += pq.top() * pq.top();  
        pq.pop();
    }
    
    return answer;
}