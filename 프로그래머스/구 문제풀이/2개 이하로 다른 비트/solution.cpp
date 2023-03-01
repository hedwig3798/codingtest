#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 홀수의 경우 1에자리에 가장 가까운 0을 1로 바꾸고 가장 먼 1을 0으로 바꾸면 된다.
long long odd(long long num){
    // 2진법을 담을 벡터
    vector<int> result;
    
    // 해당 수를 2진법화
    while(num){
        result.push_back(num % 2);
        num /= 2;
    }
    // 모든 자리가 1인 경우 예외처리
    result.push_back(0);

    // 숫자를 규칙에 맞게 변환
    for (int i = 0 ; i < result.size() ; i++){
        if (result[i] == 0){
            result[i] = 1;
            result[i-1] = 0;
            break;
        }
    }
    // 해당 수를 10진법화 한 것을 담을 변수
    long long t = 0;
    
    // 10진법화
    for (long long i = result.size()-1 ; i >= 0 ; i--){
        long long mul = 1;
        for (long long j = 0; j < result.size()-(result.size() - i); j++){
            mul *= 2;
        }
        t += result[i] * mul;
    }
    return t;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (auto i : numbers){
        // 짝수의 경우 1 더하기
        if (i % 2 == 0){
            answer.push_back(i+1);
        }
        // 홀수의 경우 위의 함수에서 설명
        else{
            answer.push_back(odd(i));
        }
    }
    return answer;
}
