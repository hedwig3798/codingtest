#include <string>
#include <vector>
#include<cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long a = 0;
    double hight = 0;
    long h = 0;
    
    long td = long(d);
    
    while (1){
        
        if ((a * k) > td){
            break;
        }
        hight = sqrt((td*td) - ((a*k) * (a*k)));
        h = floor(hight);
        
        answer += floor(h/k) + 1;
        
        a++;
    }

    
    
    
    return answer;
}