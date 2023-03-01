#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

// 최대공약수 구하는 함수
// 유클리드 호제법 사용
int gcd(int a, int b){
    int temp = 0;
    for (;b > 0;){
        temp = a;
        a = b;
        b = (temp % b);
    }
    return a;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    // arrayA 약수
    int AG = arrayA[0];
    // arrayB 약수
    int BG = arrayB[0];
    
    // 각 벡터의 최대 공약수 구하기
    for (int i = 1 ; i < arrayA.size() ; i++){
        AG = gcd(AG, arrayA[i]);
        BG = gcd(BG, arrayB[i]);
    }
    
    // A벡터값을 B의 공약수로 나누어 떨어지는지 확인
    for (int i = 0 ; i < arrayA.size() ; i++){
        if (arrayA[i] % BG == 0){
            BG = 0;
            break;
        }   
    }
    // 위와 반대
    for (int i = 0 ; i < arrayA.size() ; i++){
        if (arrayB[i] % AG == 0){
            AG = 0;
            break;
        }   
    }
    //  만일 A 벡터 값이 B공약수로 나누어 지는 경우
    if (BG == 0)
        return AG;
    // 그 반대인 경우
    if (AG == 0)
        return BG;
    // 둘 다 아닌경우 최댓값 
    return max(AG, BG);
}
