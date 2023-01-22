#include <string>
#include <vector>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    // 둘 다 오름차순 정렬
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    // a 인덱스
    int ind = 0;
    // 모든 b에 대해 반복
    for (auto b : B){
        // 만일 b가 a보다 크다면 정답을 추가하고 인덱스를 하나 
        if (A[ind] < b){
            answer++;
            ind++;
        }
    }
    return answer;
}
