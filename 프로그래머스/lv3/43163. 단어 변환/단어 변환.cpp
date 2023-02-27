#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

bool compare_string(string a, string b){
    int result = 0;
    
    for (int i = 0 ; i < a.length() ; i++){
        if (a[i] != b[i]){
            result ++;
        }
        if (result > 1)
            return false;
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    map<string, int> flag;
    queue<string> q;
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;
    
    for (auto i : words){
        flag.insert({i, 0});
    }
    flag.insert({begin, 0});
    q.push(begin);
    
    for (;!q.empty();){
        for (int i = 0 ; i < words.size() ; i++){
            if (compare_string(q.front(), words[i]) && flag[words[i]] == 0){
                if (target == words[i]){
                    return flag[q.front()] + 1;
                }
                else if (words[i] == q.front())
                    continue;
                q.push(words[i]);
                flag[words[i]] = flag[q.front()] + 1;;
            }
        }
        q.pop();
    }
    
    
    
    return answer;
}