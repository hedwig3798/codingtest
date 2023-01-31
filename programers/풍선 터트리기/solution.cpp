#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    // 좌측에서 최솟값
    vector<int> lmin(a.size());
    // 우측에서 최솟값
    vector<int> rmin(a.size());
  
    // 크기가 1이나 2인 경우 바로 리턴
    if (a.size() == 1 || a.size() == 2)
        return a.size();
    
    // 초기 촤솟값 초기화
    int l = a[0];
    int r = a.back();
    
    // 좌측 최솟값 입력
    for (int i = 0 ; i < a.size() ; i++){
        if (a[i] < l){
            l = a[i];
        }
        lmin[i] = l;
    }
    // 우측 최솟값 입력
    for (int i = a.size()-1 ; i >= 0 ; i--){
        if (a[i] < r){
            r = a[i];
        }
        rmin[i] = r;
    }
    
    // i번째 위치에서 양쪽의 최솟값을 비교하여 두 값이 모두 a[i]보다 작지 않은 경우 정답
    for (int i = 1 ; i < a.size()-1 ; i++){
        
        if (!(a[i] > lmin[i-1] && a[i] > rmin[i+1]))
            answer++;
    }
    
    return answer+2;
}
