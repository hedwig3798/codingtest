#include <bits/stdc++.h>

using namespace std;

// 원래는 이 부분으로 팬듈럼 체크를 하였지만 시간 초과가 일어나 사용하지 않았다.
bool check_pan(string s, int start, int end){
    // 시작이 끝 보다 커지면 종료
    for (;start < end;){
        // 만일 두 지점이 다르다면 팬듈럼이 아니므로
        if (s[start++] != s[end--])
            return false;
    }
    // 반복을 마치면 팬듈럼
    return true;
}

int solution(string s)
{
    int answer=0;
    // 슬라이싱 윈도우 알고리즘 사용
    // 시작지점과 끝 지점을 정하고 그것이 펜듈럼인지 체크
  
    // 윈도우 사이즈. 제한사항에 맞도록 큰 크기부터 탐색
    for (int i = s.length() ; i > 1 ; i--){
        // 시작지점 선정
        for (int j = 0 ; j < s.length() - i + 1 ; j++){
            // 팬듈럼 체크
            bool flag = true;
            int start = j;
            int end = j + i - 1;
            for (;start < end;){
                if (s[start++] != s[end--]){
                    flag = false;
                    break;
                }
            }
            if (flag)
                return i;
        }
    }

    return 1;
}
