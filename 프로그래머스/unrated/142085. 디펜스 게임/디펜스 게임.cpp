#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>> q;
    int temp = 0;
    for (int e : enemy){
        if (n >= e){
            n -= e;
            q.push(e);
            answer++;
        }
        else {
            if (k > 0){
                if (!q.empty()) {
                    temp = q.top();
                    q.pop();
                    
                    if (temp >= e){
                        k--;
                        n += temp;
                        n -= e;
                        q.push(e);
                        answer++;
                    }
                    else {
                        k--;
                        answer++;
                        q.push(temp);
                    }        
                }
                else {
                    k--;
                    answer++;
                }
            }
            else {
                break;
            }
        }
        
    }
    
    return answer;
}