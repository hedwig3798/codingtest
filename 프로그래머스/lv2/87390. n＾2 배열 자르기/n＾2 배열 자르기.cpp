#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long i = left ; i <= right ; i ++){
        int min = (i / n) + 1;
        int val = (i % n) + 1;
        
        if (val < min){
            val = min;
        }
        
        answer.push_back(val);
    }
    
    return answer;
}