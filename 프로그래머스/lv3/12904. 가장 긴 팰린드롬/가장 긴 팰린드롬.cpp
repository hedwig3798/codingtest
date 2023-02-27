#include <bits/stdc++.h>

using namespace std;

bool check_pan(string s, int start, int end){
    for (;start < end;){
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

int solution(string s)
{
    int answer=0;
    for (int i = s.length() ; i > 1 ; i--){
        for (int j = 0 ; j < s.length() - i + 1 ; j++){
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