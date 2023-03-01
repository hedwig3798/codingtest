#include <string>
#include <vector>
#include <algorithm> // revers를 위해

using namespace std;

// 진수 변환 함수
void k_changer(long long n, long long k, vector<long long> &result){
    if (n < k){
        result.push_back(n);
        return;
    }
    result.push_back(n%k);
    k_changer(n/k, k, result);
}

// 소수 판별 함수
bool is_prime(long long n){
    if (n == 2){
        return true;
    }
    else if (n == 1 || n == 0 || n % 2 == 0){
        return false;
    }
    
    for (long long i = 3 ; i*i <= n ; i += 2){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    vector<long long> c;
    // 진수 변환 후 백터로 
    k_changer(n, k, c);
    reverse(c.begin(), c.end());
    long long temp = 0;
    
    // 메인 반복문
    for (long long i : c){
        if (i == 0){
            if (is_prime(temp)){
                answer++;
            }
            temp = 0;
        }
        else {
            temp = temp*10 + i;
        }
    }
    if (is_prime(temp)){
        answer++;
        temp = 0;
    }
    
    return answer;
}
