#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    int s = 10;
    
    while(storey != 0){
        int temp = storey % s;
        //printf("%d, %d\n", storey, temp);
        if (temp == 0){

        }
        else if (temp < 5){
            answer += temp;
        }
        else if (temp > 5){
            answer += 10 - temp;
            storey += 10;
        }
        else if (temp == 5){
            int ttemp = storey % 100;
            if (ttemp >= 50){
                answer += 10 - temp;
                storey += 10;
            }
            else {
                answer += temp;
            }
        }
        storey /= 10;
        
    }
    
    
    return answer;
}