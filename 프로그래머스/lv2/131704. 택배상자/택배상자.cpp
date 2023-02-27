#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int now = 0;
    stack<int> s;
    vector<int> truck;
    
    for (int i = 1; i <= order.size(); i++){
        // printf("%d, %d\n", now, i);
        if (i == order[now]){
            now ++;
            answer ++;
        }
        else {
            s.push(i);
    
        }
        while(1){
            if (s.empty()){
                break;
            }
            if (s.top() == order[now]){
                now ++;
                answer ++;
                s.pop();
            }
            else{
                break;
            }
        }
    }
    


    return answer;
}