#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ind = 0;
    for (auto b : B){
        if (A[ind] < b){
            answer++;
            ind++;
        }
    }
    return answer;
}