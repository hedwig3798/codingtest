#include <string>
#include <vector>
using namespace std;
// 탐색 깊이
int deep = 0;
// 완전 탐색 함수
void search(vector<vector<int>> matrix, int line){
    for (int i = 0 ; i < matrix.size() ; i ++){
        if (matrix[line][i] == 1){
            deep++;
            matrix[line][i] = 0;
            matrix[i][line] = 0;
            search(matrix, i);
            matrix[line][i] = 1;
            matrix[i][line] = 1;
        }
    }
    return;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    // 전력 망을 그래프화
    vector<vector<int>> matrix (n, vector<int>(n, 0));
    
    for (auto i : wires){
        matrix[i[0]-1][i[1]-1] = 1;
        matrix[i[1]-1][i[0]-1] = 1;
    }
    
    // 각 노드를 하나씩 끊어보면서 완전탐색
    for (auto i : wires){
        // 노드를 끊음
        matrix[i[0]-1][i[1]-1] = 0;
        matrix[i[1]-1][i[0]-1] = 0;
        
        // 완전 탐색을 하면서 거친 노드의 개수
        deep = 0;
        search(matrix, 0);
        deep += 1;
        // 차이 측정
        int other = n-deep;
        if (count > abs(deep - other)){
            count = abs(deep - other);
        }
         
        // 다음 탐색을 위한 노드 
        matrix[i[0]-1][i[1]-1] = 1;
        matrix[i[1]-1][i[0]-1] = 1;
    }
    
    return count;
}
