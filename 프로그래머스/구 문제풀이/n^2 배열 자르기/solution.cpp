#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    // left 와 right 사이만큼 반복
    for (long long i = left ; i <= right ; i ++){
        // 나올 수 있는 최솟값
        int min = (i / n) + 1;
        // 그 행의 값
        int val = (i % n) + 1;
        if (val < min){
            val = min;
        }
        
        answer.push_back(val);
    }
    
    return answer;
}
