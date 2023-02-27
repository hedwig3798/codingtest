#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    stack<int> s;
    
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            if (computers[i][j] == 1){
                s.push(j);
                computers[i][j] = 0;
                computers[j][i] = 0;
            }
        }
        if (!s.empty()){
            answer++;
            for(;!s.empty();){
                int temp = s.top();
                s.pop();
                for (int k = 0; k < n ; k++){
                    if (computers[temp][k] == 1){
                        computers[temp][k] = 0;
                        computers[k][temp] = 0;
                        s.push(k);
                    }
                }
                
            }
        }
    }
    
    return answer;
}