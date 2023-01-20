#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    // n이 s보다 큰 경우 절대 불가능하다
    if (s/n == 0){
        answer.push_back(-1);
    }
    else{
        // 규칙에 따라 수를 입력하면 
        for (;n >=1;){
            answer.push_back(s/n);
            s = s - s/n;
            n--;
        }
    }
    return answer;
}
