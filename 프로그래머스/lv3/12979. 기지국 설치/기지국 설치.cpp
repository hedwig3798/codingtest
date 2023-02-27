#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int left = 1;
    int right = 1;
    int sub = 0;
    int start = 1;
    for (auto i : stations){
        left = (i - w < 1) ? 1 : i-w;
        right = (i + w > n) ? n : i+w;
        
        sub = left - start;
        if (sub <= 0){
            start = right + 1;
            continue;
        }
        answer += sub / ((w*2)+1);
        if (sub % ((w*2)+1) != 0)
            answer++;
        start = right + 1;
    }
    
    if (start <= n){
        sub = n - start + 1;
        answer += sub / ((w*2)+1);
        if (sub % ((w*2)+1) != 0)
            answer++;
    }
    
    return answer;
}