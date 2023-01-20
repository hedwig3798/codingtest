#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    // 최대 힙 생성 (우선순위 큐)
    priority_queue<long long, vector<long long>, less<long long>> pq;
    
    // 힙에 값 입력
    for (auto i : works){
        pq.push((long long)i);
    }
    
    // 힙에서 하나씩 꺼내어 1을 감소하고 다시 넣음
    for (int i = 0 ; i < n ; i++){
        long long temp = pq.top();
        if (pq.top() == 0){
            return 0;
        }
        pq.pop();
        pq.push(temp-1);
    }
    
    // 힙이 빌 때까지 하나씩 빼면서 제곱한 값을 
    for (;!pq.empty();){
        answer += pq.top() * pq.top();  
        pq.pop();
    }
    
    return answer;
}
