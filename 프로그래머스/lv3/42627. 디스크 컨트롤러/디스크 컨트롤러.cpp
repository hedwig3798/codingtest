#include <bits/stdc++.h>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    sort(jobs.begin(), jobs.end());
    
    int now = 0;
    int ind = 0;
    for (;ind < jobs.size() || !pq.empty();){
        if (ind < jobs.size() && jobs[ind][0] <= now){
            pq.push(jobs[ind]);
            ind++;
            continue;
        }
        
        if (!pq.empty()){
            now += pq.top()[1];
            answer += now - pq.top()[0];
            pq.pop();
        }
        else {
            now = jobs[ind][0];
        }
    }
    
    return answer / jobs.size();
}