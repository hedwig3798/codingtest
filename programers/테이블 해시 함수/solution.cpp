#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// col을 정렬 함수에서 쓰기 위한 전역변수
int standard;
// 정렬 함수
bool cmp (vector<int> a, vector<int> b){
    if (a[standard] == b[standard]){
        return a[0] > b[0];
    }
    return a[standard] < b[standard];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    // col을 정렬 함수에서 쓰기 위해
    standard = col-1;
    // 제한사항에 맞게 정렬
    sort(data.begin(), data.end(), cmp);
    // 범위 내 반복
    for (int i = row_begin-1; i < row_end ; i ++){
        int sum = 0;
        // 나머지 더한 값
        for (int j : data[i]){
            sum += j % (i+1);
        }
        // bitwise xor 계산
        answer = answer ^ sum;
    }
    
    return answer;
}
