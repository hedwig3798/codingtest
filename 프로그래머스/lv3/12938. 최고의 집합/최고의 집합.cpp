#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (s/n == 0){
        answer.push_back(-1);
    }
    else{
        for (;n >=1;){
            answer.push_back(s/n);
            s = s - s/n;
            n--;
        }
    }
    return answer;
}