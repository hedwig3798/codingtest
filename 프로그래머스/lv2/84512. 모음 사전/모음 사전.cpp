#include <string>
#include <vector>

using namespace std;

int answer = 0;
string w;
string alp[5] = {"A", "E", "I", "O", "U"};

bool dfs(string s){
    //printf("%s\n", s.c_str());
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