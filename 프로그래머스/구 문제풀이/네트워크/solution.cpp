#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    // bfs용으로 사용할려 했지만 스텍이 아닌 큐를 사용하여야 한다.
    stack<int> s;
    
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            // 해당 노드와 연결된 노드가 있다면
            if (computers[i][j] == 1){
                // 스텍에 넣고 연결을 지운다.
                s.push(j);
                computers[i][j] = 0;
                computers[j][i] = 0;
            }
        }
        // 연결된 것이 있다면
        if (!s.empty()){
            // 네트워크가 하나 형성된다.
            answer++;
            // 스텍이 빌 때까지
            for(;!s.empty();){
                // 맨 윗값을 가져온다.
                int temp = s.top();
                s.pop();
                // 해당 노드와 연결된 다른 노드가 있다면 스텍에 넣는다.
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
