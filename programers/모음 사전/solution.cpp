#include <string>
#include <vector>

using namespace std;

int answer = 0;
string w;
string alp[5] = {"A", "E", "I", "O", "U"};

// 깊이 우선 탐색
// 문자열을 하나의 트리처럼 생각함
bool dfs(string s){
    answer++;
    if (s == w){
        return true;
    }
    if (s.size() == 5) 
        return false;
    
    for (string j : alp){
        if (dfs(s + j)) 
            return true;
    }
    return false;
}

int solution(string word) {
    w = word;
    for (string i : alp){
        if (dfs(i)) return answer;
    }
    
    return answer;
}
