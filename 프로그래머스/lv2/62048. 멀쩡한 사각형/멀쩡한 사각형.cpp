#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    long long we = (long long)w;
    long long hi = (long long)h;
    for (long long i = 1 ; i < we ; i++){
        answer += (hi*i)/we;
    }
    
    return answer*2;
}