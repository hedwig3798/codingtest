#include <string>
#include <vector>
#include <iostream>
using namespace std;
// 배열이 같은 값으로 채워져 있는지 검사하는 함수
bool same(vector<int>arr){
    int check = arr[0];
    for (auto i : arr){
        if (arr[0] != i)
            return false;
    }
    return true;
}

// 4등분 하며 조건에 맞게 배열을 만드는 함수
vector<int> split (vector<int> arr, int size){
    // 크기가 1 이하이면 분할이 불가능하므로 바로 리턴
    if (size <= 1)
        return arr;
    // 4등분을 위한 벡터
    vector<vector<int>> v (4, vector<int>());
    // 4등분
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
    // 각 배열이 같은 수로 채워져 있는지 검사
    for (int i = 0 ; i < 4 ; i++){
        // 만일 그렇다면 해당 백터을 그 숫자만 있는 벡터로 치환
        if (same(v[i])){
            int s = v[i][0];
            v[i].clear();
            v[i].push_back(s);
        }
        // 아니라면 다시 나눔
        else
            v[i] = split(v[i], size/2);
    }
    // 백터를 합쳐서 리턴
    vector<int> result;
    for (int i = 0 ; i < 4 ; i++){
        result.insert(result.end(), v[i].begin(), v[i].end());
    }
    return result;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    // 2차원 백터를 편의를 위해 선형으로 바꿈
    vector<int> liner;
    int size = arr.size();
    // 백터 선형화
    for (auto i : arr){
        for (auto j : i){
            liner.push_back(j);
        }
    }
    
    // 쿼드 압축 실행
    vector<int> result = split(liner, size);
    
    // 백터는 최소 4등분이 되므로 모든 값이 같다면 [1, 1, 1, 1] || [0, 0, 0, 0] 과 같은 값이 나오므로 체크
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
    
    // 남은 배열의 숫자 종류 갯수 세기
    int zero = 0;
    int one = 0;
    
    for (auto i : result){
        if (i == 0)
            zero++;
        else if (i == 1)
            one++;
    }
    
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}
