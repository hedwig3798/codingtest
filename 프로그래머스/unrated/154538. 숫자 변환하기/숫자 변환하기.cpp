#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    int result[1000000];
    
    result[x] = 0;
    
    for (int i = x+1 ; i <= y ; i++){
        int a = INF;
        int b = INF;
        int c = INF;
        
        if (i % 2 == 0 && i / 2 >= x)
            a = result[i / 2];
        if (i % 3 == 0 && i / 3 >= x)
            b =  result[i / 3];
        if (i - n >= 0 && i - n >= x)
            c = result[i - n];
        
        int r;
        r = min(a, b);
        r = min(r, c);
        
        result[i] = (r < INF) ? ++r : INF;
    }
    answer = (result[y] < INF) ? result[y] : -1;
    return answer;
}