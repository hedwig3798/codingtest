#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

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
    
    // if (arrayA.size() == 1){
    //     return gcd(arrayA[0], arrayB[0]);
    // }
    
    
    int AG = arrayA[0];
    int BG = arrayB[0];
    
    for (int i = 1 ; i < arrayA.size() ; i++){
        AG = gcd(AG, arrayA[i]);
        BG = gcd(BG, arrayB[i]);
    }
    
    for (int i = 0 ; i < arrayA.size() ; i++){
        if (arrayA[i] % BG == 0){
            BG = 0;
            break;
        }   
    }
    
    for (int i = 0 ; i < arrayA.size() ; i++){
        if (arrayB[i] % AG == 0){
            AG = 0;
            break;
        }   
    }
    
    //cout << AG << ' ' << BG << endl;
    
    if (BG == 0)
        return AG;
    if (AG == 0)
        return BG;
    return max(AG, BG);
}