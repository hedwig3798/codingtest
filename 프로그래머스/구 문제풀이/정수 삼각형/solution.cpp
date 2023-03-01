#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    // bottom-up방식. 삼각형의 밑바닥에서 가장 최선의 선택만 하여 위로 더함
    for (int i = triangle.size()-2 ; i >= 0 ; i--){
        for (int j = 0 ; j < triangle[i].size() ; j++){
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }
    // 삼각형 마지막에는 누적합이 있으므로
    return triangle[0][0];
}
