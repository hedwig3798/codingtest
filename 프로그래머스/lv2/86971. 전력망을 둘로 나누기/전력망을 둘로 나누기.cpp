#include <string>
#include <vector>
using namespace std;
int count = 100;
int deep = 0;
// 디버깅용 함수
void pprint(vector<int> i){
    for (int t : i){
        printf("%d ", t);
    }
    printf("\n");
}

// 디버깅용 함수
void ppprint(vector<vector<int>> i){
    for (vector<int> t : i){
        pprint(t);
    }
    printf("\n");
}

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
    vector<vector<int>> matrix (n, vector<int>(n, 0));
    
    for (auto i : wires){
        matrix[i[0]-1][i[1]-1] = 1;
        matrix[i[1]-1][i[0]-1] = 1;
    }
    
    count = n-1;
    
    for (auto i : wires){
        matrix[i[0]-1][i[1]-1] = 0;
        matrix[i[1]-1][i[0]-1] = 0;
        deep = 0;
        search(matrix, 0);
        deep += 1;
        int other = n-deep;
        if (count > abs(deep - other)){
            count = abs(deep - other);
        }
        
        matrix[i[0]-1][i[1]-1] = 1;
        matrix[i[1]-1][i[0]-1] = 1;
    }
    
    return count;
}