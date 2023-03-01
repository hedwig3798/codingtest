#include <string>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    
    // 두 큐의 총 합을 미리 구하여 놓아 시간 복잡도 감소
    // 문제 제한 사항에 따라 오버플로우를 우려하여 LL형 변수형 사용
    long long a = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long b = accumulate(queue2.begin(), queue2.end(), 0LL);
    
    // 위 변수와 마찬가지
    long long count = queue1.size()*4;
    
    // 인덱스의 경우 int 변수 안에서도 충분할 것이라 생각함
    // erase 대신 벡터를 길게 늘이고 시작 인덱스를 같이 수정하는 방식으로 사용함 -> 시간복잡도 절약
    int q1_inx = 0;
    int q2_inx = 0;
    
    // 반복 시작
    for (int i = 0 ; i < count ; i ++){
        // 탈출 코드. 해당 조건을 만족하지 못하고 나오는 경우 answer는 -1이 됨
        if (a == b){
            answer = i;
            break;
        }
        // dequeue & enqueue 과정
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
