#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    // 기준 변수
    int s = 10;
    // storey 변수의 1의자리부터 줄여가며 구함
    while(storey != 0){
        // 1의 자리 파악
        int temp = storey % s;
        // 예외 처리
        if (temp == 0){

        }
        // 5 이하인 경우 그냥 내려감
        else if (temp < 5){
            answer += temp;
        }
        // 5 이상인 경우 위로 올라간 후 내려감
        else if (temp > 5){
            answer += 10 - temp;
            storey += 10;
        }
        // 5 인 경우 다음 자리를 보고 결정
        else if (temp == 5){
            int ttemp = storey % 100;
            // 다음 자리가 50 이상이면 올라가는 것이 이득
            if (ttemp >= 50){
                answer += 10 - temp;
                storey += 10;
            }
            // 아닌 경우 내려가는 것이 이득
            else {
                answer += temp;
            }
        }
        // 필요없는 자릿수 
        storey /= 10;
        
    }
    
    
    return answer;
}
