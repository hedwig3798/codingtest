#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    long long d = 0;
    long long p = 0;
    for (int i = n-1 ; i >= 0 ; i--){
        
        long long count = 0;
        d += deliveries[i];
        p += pickups[i];
        for (;d > 0 || p > 0;){
            count++;
            d -= cap;
            p -= cap;
        }
        answer += (i + 1) * 2 * count;
    }
    
    return answer;
}