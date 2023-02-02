#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    // 각 금액을 표시
    vector<long long> result(n+1, 0);
    // 최솟값
    result[0] = 1;
    
    // 각 동전들을 하나씩 순회
    for (auto i : money){
        // 그 동전 금액에서부터 n까지
        for (long long j = i ; j <= n ; j++){
            // 그 동전을 하나 냈다고 가정하고 얼마를 더 내야 하는지
            long long count = j - i;
            // 그 금액을 낼 수 있는 가짓수는 이미 정해져 있으므로
            result[j] += result[count];
        }
    }
    // 제한사항에 맞게 
    return (int)(result.back() % 1000000007);
}
