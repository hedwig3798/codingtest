#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long odd(long long num){
    vector<int> result;

    while(num){
        result.push_back(num % 2);
        num /= 2;
    }
    result.push_back(0);

    
    for (int i = 0 ; i < result.size() ; i++){
        if (result[i] == 0){
            result[i] = 1;
            result[i-1] = 0;
            break;
        }
    }
    long long t = 0;
    // for (int i = result.size()-1 ; i >= 0 ; i--){
    //     printf("%d",result[i] );
    // }
    // printf("\n");
    for (long long i = result.size()-1 ; i >= 0 ; i--){
        long long mul = 1;
        for (long long j = 0; j < result.size()-(result.size() - i); j++){
            mul *= 2;
        }
        t += result[i] * mul;
        //printf("%ld\n", t);
    }
    return t;
}
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (auto i : numbers){
        if (i % 2 == 0){
            answer.push_back(i+1);
        }
        else{
            answer.push_back(odd(i));
        }
    }
    return answer;
}