#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> tri;
        
    for (int i = 0 ; i < n ; i++){
        tri.push_back(vector<int>(i+1, 0));
    }
    
    int top = 0;
    int bot = n-1;
    int left = 0;
    int right = 0;
    int dir = 0;
    int num = 1;
    for (int i = 0 ; i < tri.size(); i++){
        if (dir == 0){
            for (int j = top ; j <= bot ; j++){
                tri[j][left] = num++;
            }
            top++;
            left++;
            dir = 1;
        }
        else if (dir == 1){
            for (int j = left ; j <= bot - right ; j++){
                tri[bot][j] = num++;
            }
            bot--;
            dir = 2;
        }
        else if (dir == 2){
            for (int j = bot ; j >= top ; j--){
                tri[j][j-right] = num++;
            }
            right++;
            top++;
            dir = 0;
        }
        
    }
    
    for (auto k : tri){
        for (auto l : k){
            answer.push_back(l);
        }
    }

    
    
    return answer;
}