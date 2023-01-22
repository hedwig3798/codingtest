#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 정렬 함수. 나오는 지점 기준으로 오름차순 정렬
bool cmp (vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    // 카메라가 담길 벡터
    vector<int> c;
    // 나오는 지점 기준 정렬
    sort(routes.begin(), routes.end(), cmp);
    // 모든 루트에 대해서 반복
    for (auto r : routes){
        // 비어있다면 (첫 차량 이라면) 해당 차량의 나오는 지점을 벡터에 입력
        if (c.empty()){
            c.push_back(r[1]);
        }
        // 만일 현재 차량이 마지막 카메라에 잡히는 경우 continue
        else if (c.back() >= r[0]){
            continue;
        }
        // 잡히지 않으면 카메라에 입력
        else {
            c.push_back(r[1]);
        }     
    }
    // 카메라의 개수 
    return c.size();
}
