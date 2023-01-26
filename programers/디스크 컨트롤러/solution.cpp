#include <bits/stdc++.h>

using namespace std;

// 비교 구조체
struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    // 작업 시간이 짧은 순으로 정렬된 우선순위 큐
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    // 요청 시간 순 정렬
    sort(jobs.begin(), jobs.end());
    
    // 현재 시간
    int now = 0;
    // 현재 작업
    int ind = 0;
    // 큐가 비고 작업이 남지 않을 때 까지
    for (;ind < jobs.size() || !pq.empty();){
        // 요청 시간이 현재 시간보다 적다면 큐에 넣음
        if (ind < jobs.size() && jobs[ind][0] <= now){
            pq.push(jobs[ind]);
            ind++;
            continue;
        }
        
        // 큐에 넣지 못하는 작업이 왔는데 큐에 작업 내용이 있는경우
        if (!pq.empty()){
            // 현재 시간에 실행 시간을 더한다
            now += pq.top()[1];
            // 총 소요 시간을 정답에 더한다.
            answer += now - pq.top()[0];
            pq.pop();
        }
        // 큐에 넣지 못하는 작업이 왔는데 큐에 작업 내용이 없는 경우
        else {
            // 현재 시간을 해당 작업의 요청 시간으로 바꾼다.
            now = jobs[ind][0];
        }
    }
    // 총 소요 시간을 크기로 나누면 
    return answer / jobs.size();
}
