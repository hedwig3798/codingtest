#include <string>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    
    long long a = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long b = accumulate(queue2.begin(), queue2.end(), 0LL);
    
    long long count = queue1.size()*4;
    
    int q1_inx = 0;
    int q2_inx = 0;
    
    for (int i = 0 ; i < count ; i ++){
        if (a == b){
            answer = i;
            break;
        }
        else if (a < b){
            b -= queue2[q2_inx];
            a += queue2[q2_inx];
            
            queue1.push_back(queue2[q2_inx]);
            q2_inx++;
        }
        else if (a > b){
            b += queue1[q1_inx];
            a -= queue1[q1_inx];
            
            queue2.push_back(queue1[q1_inx]);
            q1_inx++;
        }
    }
    
    return answer;
}