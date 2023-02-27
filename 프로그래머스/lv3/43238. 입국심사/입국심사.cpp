#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    long long start = (long long)times[0];
    long long end = (long long)n * (long long)times[0];
    answer = (long long)n * (long long)times[0];
    
    for (;start <= end;){
        long long mid = (start + end) / 2;
        long long human = 0;
        for (auto i : times){
            human += mid / i;
            
            if (human >= n){
                answer = mid;
                end = mid-1;
                break;
            }
        }
        if (human < n){
            start = mid+1;
        }
    }
    
    
    
    return answer;
}