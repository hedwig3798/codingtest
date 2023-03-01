#include <string>
#include <vector>

using namespace std;

int solution(int n, long long l, long long r) {
    int answer = 0;
    
    // 범위 내 반복
    // 해당 숫자가 1인지 0인지 파악
    for (long long i = l; i <= r ; i++){
        // 해당 숫자가 1인지 0인지 알려주는 플레그
        int flag = 1;
        
        // 만일 해당 숫자가 3번째 숫자라면 반드시 0이므로 (11011, 00000, 두가지중 하나 이므로)
        if (i % 5 == 3){
            continue;
        }
        // i 값을 변화시킬 예정이므로 복사해서 사용
        long long temp = i;
        // 그 값의 위로 올라가면서 윗 라인에 0이 한번이라도 있는지 파악, 만일 있다면 무조건 0
        while (1){
          
            // 5의 배수의 경우 예외 처리
            if (temp % 5 == 0){
                temp = temp / 5;
            }
            else {
                temp = (temp / 5) + 1;
            }
             
            // 0이 있는 경우
            if (temp % 5 == 3){
                flag = 0;
                break;
            }
            // 0이 아니면서 n = 1 인 비트열에 도달한 경우
            else if (temp <= 5){
                flag = 1;
                break;
            }
        }
        // 1이면 
        if (flag == 1) answer++;
    }
    
    return answer;
}
