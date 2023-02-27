#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b){
    if (a.second > b.second)
        return true;
    return false;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<string, int> hash;
    string temp = "";
    for (auto i : s){
        if (i >= '0' && i <= '9'){
            temp += i;
        }
        else if (temp == ""){
            continue;
        }
        else {
            if (hash.find(temp) == hash.end()){
                hash.insert({temp, 1});
            }
            else {
                hash[temp]++;
            }
            temp = "";
        }
    }
    
    vector<pair<string, int>> storage;
    
    for (auto i : hash){
        storage.push_back(i);
    }
    
    sort(storage.begin(), storage.end(), cmp);
    
    for (auto i : storage){
        answer.push_back(stoi(i.first));
    }
    
    
    return answer;
}