#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check(int i, int j, vector<string> &places){
    
    if (places[i-1][j] == 'P' || places[i+1][j] == 'P' || places[i][j-1] == 'P' || places[i][j+1] == 'P')
        return true;
    
    if ((places[i-2][j] == 'P' && places[i-1][j] == 'O') || 
        (places[i+2][j] == 'P' && places[i+1][j] == 'O') || 
        (places[i][j-2] == 'P' && places[i][j-1] == 'O') || 
        (places[i][j+2] == 'P' && places[i][j+1] == 'O')){
        
        return true;
    }
        
    
    if ((places[i+1][j+1] == 'P' && (places[i+1][j] == 'O' || places[i][j+1] == 'O')) || 
        (places[i+1][j-1] == 'P' && (places[i+1][j] == 'O' || places[i][j-1] == 'O')) || 
        (places[i-1][j+1] == 'P' && (places[i-1][j] == 'O' || places[i][j+1] == 'O')) || 
        (places[i-1][j-1] == 'P' && (places[i-1][j] == 'O' || places[i][j-1] == 'O')))
        return true;
    
    return false;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    vector<vector<string>> expend_places(places.size(), vector<string>(9, "XXXXXXXXX"));
    for (int k = 0 ; k < places.size() ; k++){
        for (int i = 2 ; i < 7 ; i++){
            for (int j = 2 ; j < 7 ; j++){
                expend_places[k][i][j] = places[k][i-2][j-2];
            }
        }
    }
    
    for (auto k : expend_places){
        bool flag = true;
        for (int i = 2 ; i < k.size()-2 ; i++){
            for (int j = 2 ; j < k[0].size()-2 ; j++){
                if (k[i][j] == 'P'){
                    if (check(i, j, k)){
                        answer.push_back(0);
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag)
                break;
        }
        if (flag)
            answer.push_back(1);
        
    }
    
    return answer;
}