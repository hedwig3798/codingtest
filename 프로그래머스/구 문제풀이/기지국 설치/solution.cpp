#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    // 초기값 목록
    // 해당 기지국의 가장 왼쪽 값
    int left = 1;
    // 해당 기지국의 가장 오른쪽 값
    int right = 1;
    // 시작지점과 왼쪽지접의 차
    int sub = 0;
    // 시작지점
    int start = 1;
    for (auto i : stations){
        // 변수에 맞도록
        left = (i - w < 1) ? 1 : i-w;
        right = (i + w > n) ? n : i+w;
        sub = left - start;
        // 겹치는 경우 예외처리
        if (sub <= 0){
            start = right + 1;
            continue;
        }
        // 정답 더하기
        answer += sub / ((w*2)+1);
        if (sub % ((w*2)+1) != 0)
            answer++;
        // 시작지점 이동
        start = right + 1;
    }
    // 마지막에 
    if (start <= n){
        sub = n - start + 1;
        answer += sub / ((w*2)+1);
        if (sub % ((w*2)+1) != 0)
            answer++;
    }
    
    return answer;
}
