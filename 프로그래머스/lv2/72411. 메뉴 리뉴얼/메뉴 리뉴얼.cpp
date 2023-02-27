#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map <string, int> table;

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

void insertMap(string menu, int depth, int ind, string temp){
    if (temp.length() == depth){
        table[temp] += 1;
        return;
    }
    for (int i = ind; i < menu.length(); i++){
        temp[depth] = menu[i];
        insertMap(menu, depth+1, i+1, temp);
    }
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (string menu : orders){
        sort(menu.begin(), menu.end());
        for (int count : course){
            string temp = "";
            temp.resize(count);
            insertMap(menu, 0, 0, temp);
        }
    }
    
    vector<pair<string, int>> result;
    for (auto i : table){
        if (i.second < 2)
            continue;
        else
            result.push_back(i);
    }
    sort(result.begin(), result.end(), cmp);
    
    for (auto i : course){
        int max = 0;
        for (auto j : result){
            if (j.first.length() != i) continue;

            if (max == 0 || max == j.second) {
                max = j.second;
                answer.push_back(j.first);
            }
            else break;
        }
        
    }
    sort(answer.begin(), answer.end());
    return answer;
}