#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<int> solution(int n) {
    vector<int> answer;
    // 삼각형 백터
    vector<vector<int>> tri;
        
    // 미리 삼각형 모양의 공간을 만들기
    for (int i = 0 ; i < n ; i++){
        tri.push_back(vector<int>(i+1, 0));
    }
    
    // 채워진 가장 윗 라인
    int top = 0;
    // 채워진 가장 아랫 라인
    int bot = n-1;
    // 채워진 가장 왼쪽 라인
    int left = 0;
    // 채워진 가장 오른쪽 라인
    int right = 0;
    // 방향
    int dir = 0;
    // 숫자
    int num = 1;
  
    // 최댓값 (1 ~ n 까지의 합) 까지 반복
    for (int i = 0 ; i < tri.size(); i++){
        // 아래로 내려가는 경우
        if (dir == 0){
            // 수를 채우고
            for (int j = top ; j <= bot ; j++){
                tri[j][left] = num++;
            }
            // 윗 라인과 왼쪽 라인이 한칸씩 채워짐. 이하 동일
            top++;
            left++;
            dir = 1;
        }
        // 오른쪽으로 가는 경우
        else if (dir == 1){
            for (int j = left ; j <= bot - right ; j++){
                tri[bot][j] = num++;
            }
            bot--;
            dir = 2;
        }
        // 왼쪽으로 가는 경우
        else if (dir == 2){
            for (int j = bot ; j >= top ; j--){
                tri[j][j-right] = num++;
            }
            right++;
            top++;
            dir = 0;
        }
        
    }
    
    // 삼각형을 선형으로 
    for (auto k : tri){
        for (auto l : k){
            answer.push_back(l);
        }
    }

    
    
    return answer;
}
