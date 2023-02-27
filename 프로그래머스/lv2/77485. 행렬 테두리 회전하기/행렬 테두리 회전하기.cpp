#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> matirx(rows, vector<int> (columns, 0));
    
    for (int i = 0; i < matirx.size() ; i++){
        for (int j = 0 ; j < matirx[0].size() ; j++){
            matirx[i][j] = (i*matirx[0].size()) + j + 1;
        }
    }
    
//     for (auto i : matirx){
//         for (auto j : i){
//             printf("%d ", j);
//         }
//         printf("\n");
//     }
//     printf("\n");
    
    for (auto q : queries){
        vector<int> temp;
        int min = 100000;
        int x1 = q[1];
        int x2 = q[3];
        int y1 = q[0];
        int y2 = q[2];
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

        rotate(temp.begin(), temp.end() - 1 , temp.end()); 
        int ind = 0;
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
            
        // for (auto i : temp){
        //     printf("%d ", i);
        // }
        // printf("\n");
        // for (auto i : matirx){
        //     for (auto j : i){
        //         printf("%d ", j);
        //     }
        //     printf("\n");
        // }
        // printf("\n");  
        answer.push_back(*min_element(temp.begin(), temp.end()));
    }
    
    return answer;
}