#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    // y의 최대 크기
    int result[1000000];
    // x 위치에는 0번쨰 도달
    result[x] = 0;
    
    for (int i = x+1 ; i <= y ; i++){
        // 각 방법으로 탐색
        int a = INF;
        int b = INF;
        int c = INF;
        
        // 2를 곱해서 i가 되는 수
        if (i % 2 == 0 && i / 2 >= x)
            a = result[i / 2];
        // 3을 곱해서 i가 되는 수
        if (i % 3 == 0 && i / 3 >= x)
            b =  result[i / 3];
        // n을 더해서 i가 되는 수
        if (i - n >= 0 && i - n >= x)
            c = result[i - n];
        
        // 각 수 중 최솟값을 가져옴
        int r;
        r = min(a, b);
        r = min(r, c);
        // 만일 유효한 값이면 +1을 한 값을 i에 넣음
        result[i] = (r < INF) ? ++r : INF;
    }
    // y값이 유효하면 정답, 아니라면 -1이 정답
    answer = (result[y] < INF) ? result[y] : -1;
    return answer;
}
