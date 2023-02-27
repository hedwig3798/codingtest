#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool same(vector<int>arr){
    int check = arr[0];
    for (auto i : arr){
        if (arr[0] != i)
            return false;
    }
    return true;
}

vector<int> split (vector<int> arr, int size){
    if (size <= 1)
        return arr;
    
    vector<vector<int>> v (4, vector<int>());
    
    // for (int i = 0 ; i < size ; i++){
    //     for (int j = 0 ; j < size ; j++){
    //         cout << arr[i*size + j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
    for (int i = 0 ; i < size ; i++){
        for (int j = 0 ; j < size ; j++){
            if (i < (size/2) && j < (size/2))
                v[0].push_back(arr[i*size + j]);
            else if (i < (size/2) && j >= (size/2))
                v[1].push_back(arr[i*size + j]);
            else if (i >= (size/2) && j < (size/2))
                v[2].push_back(arr[i*size + j]);
            else if (i >= (size/2) && j >= (size/2))
                v[3].push_back(arr[i*size + j]);
        }
    }
    
    for (int i = 0 ; i < 4 ; i++){
        if (same(v[i])){
            int s = v[i][0];
            v[i].clear();
            v[i].push_back(s);
        }
        else
            v[i] = split(v[i], size/2);
    }
    
    // for (int i = 0 ; i < 4 ; i++){
    //     for (auto j : v[i]){
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
    vector<int> result;
    for (int i = 0 ; i < 4 ; i++){
        result.insert(result.end(), v[i].begin(), v[i].end());
    }
    
    return result;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    vector<int> liner;
    int size = arr.size();
    for (auto i : arr){
        for (auto j : i){
            liner.push_back(j);
        }
    }
    
    vector<int> result = split(liner, size);
    
    if (same(result)){
        if (result[0] == 0){
            answer.push_back(1);
            answer.push_back(0);
        }
        else if (result[0] == 1){
            answer.push_back(0);
            answer.push_back(1);
        }
        return answer;
    }
    
    int zero = 0;
    int one = 0;
    
    for (auto i : result){
        //cout << i << ' ';
        if (i == 0)
            zero++;
        else if (i == 1)
            one++;
    }
    
    
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}