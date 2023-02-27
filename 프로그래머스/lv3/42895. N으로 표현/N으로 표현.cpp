#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    if (number == N)
        return 1;
    if (number == N + N*10 || number == N+N || number == N*N || number == 1 || number == 0)
        return 2;
    
    vector<set<int>> result(8, set<int>());
    result[0].insert(N);
    result[1].insert(N + N*10);
    result[1].insert(N+N);
    result[1].insert(N*N);
    result[1].insert(0);
    result[1].insert(1);
    
    for (int i = 2 ; i < 8 ; i++){
        int temp = 0;
        for (int k = 0 ; k <= i ; k++){
            temp = temp*10 + N;
        }
        result[i].insert(temp);
        for (int j = 0 ; j < i ; j++){
            for (auto a : result[j]){
                for (auto b : result[i-j-1]){
                    if (number == a+b || number == a*b || number == a-b)
                        return i+1;
                    else if (b != 0 && a%b == 0 && number == a/b)
                        return i+1;
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