#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    // 결과가 1, 2인 경우 예외처리
    if (number == N)
        return 1;
    if (number == N + N*10 || number == N+N || number == N*N || number == 1 || number == 0)
        return 2;
    
    // 1, 2 인경우 결과값을 미리 입력
    // 중복 제거를 위해 set 사용
    vector<set<int>> result(8, set<int>());
    result[0].insert(N);
    result[1].insert(N + N*10);
    result[1].insert(N+N);
    result[1].insert(N*N);
    result[1].insert(0);
    result[1].insert(1);
    
    // N을 3번 이상 쓰는 경우
    for (int i = 2 ; i < 8 ; i++){
        // NNN인 경우 포함 ex) N = 5 일때 5, 55, 555 같은 경우
        int temp = 0;
        for (int k = 0 ; k <= i ; k++){
            temp = temp*10 + N;
        }
        result[i].insert(temp);
      
        // 이전 결과를 참고하여 현재 가능한 경우의 수 탐색
        for (int j = 0 ; j < i ; j++){
            // j 일때
            for (auto a : result[j]){
                // i-j-1 값과 연산하는 경우
                for (auto b : result[i-j-1]){
                    // 만일 +, -, * 중에 결과가 나오는 경우
                    if (number == a+b || number == a*b || number == a-b)
                        return i+1;
                    // / 중에 결과가 나오는 경우, 이때 b = 0인 경우 나누기가 안되므로 예외처리
                    else if (b != 0 && a%b == 0 && number == a/b)
                        return i+1;
                    // 결과가 나오지 않는 경우 result에 현재 
                    else {
                        result[i].insert(a+b);
                        result[i].insert(a*b);
                        result[i].insert(a-b);
                        if (b != 0 && a%b == 0)
                            result[i].insert(a/b);
                    }
                }
            }
        }
    }
    
    return answer;
}
