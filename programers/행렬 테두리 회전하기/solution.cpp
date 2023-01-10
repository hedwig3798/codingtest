#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    // 보드 만들기
    vector<vector<int>> matirx(rows, vector<int> (columns, 0));
    // 보드에 값 넣기
    for (int i = 0; i < matirx.size() ; i++){
        for (int j = 0 ; j < matirx[0].size() ; j++){
            matirx[i][j] = (i*matirx[0].size()) + j + 1;
        }
    }
    // 쿼리 실행
    for (auto q : queries){
        // 테두리 값 저장을 위한 벡터
        vector<int> temp;
        // 보기 편하라고 값 변경
        int x1 = q[1];
        int x2 = q[3];
        int y1 = q[0];
        int y2 = q[2];
      
        // 테두리 값 저장
        for (int i = x1-1 ; i < x2; i++){
            temp.push_back(matirx[y1-1][i]);
        }
        for (int i = y1 ; i < y2; i++){
            temp.push_back(matirx[i][x2-1]);
        }
        for (int i = x2-2 ; i >= x1-1 ; i--){
            temp.push_back(matirx[y2-1][i]);
        }
        for (int i = y2-2 ; i > y1-1 ; i--){
            temp.push_back(matirx[i][x1-1]);
        }
        // 벡터 한칸씩 회전
        rotate(temp.begin(), temp.end() - 1 , temp.end()); 
        int ind = 0;
        // 회전한 테두리 값을 다시 입력
        for (int i = x1-1 ; i < x2; i++){
            matirx[y1-1][i] = temp[ind++];
        }
        for (int i = y1 ; i < y2; i++){
           matirx[i][x2-1] = temp[ind++];
        }
        for (int i = x2-2 ; i >= x1-1 ; i--){
            matirx[y2-1][i] = temp[ind++];
        }
        for (int i = y2-2 ; i > y1-1 ; i--){
            matirx[i][x1-1] = temp[ind++];
        }
        // 최솟값 
        answer.push_back(*min_element(temp.begin(), temp.end()));
    }
    
    return answer;
}
