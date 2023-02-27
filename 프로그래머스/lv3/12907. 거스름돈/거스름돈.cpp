#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<long long> result(n+1, 0);
    result[0] = 1;
    
    for (auto i : money){
        for (long long j = i ; j <= n ; j++){
            long long count = j - i;
            result[j] += result[count];
        }
    }
  
    return (int)(result.back() % 1000000007);
}