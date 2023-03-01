#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// 정렬 함수
bool cmp(pair<string, int> a, pair<string, int> b){
    if (a.second > b.second)
        return true;
    return false;
}

vector<int> solution(string s) {
    vector<int> answer;
    // 숫자의 등장 횟수를 담을 맵
    map<string, int> hash;
    // 숫자 정보를 담을 변수
    string temp = "";
    for (auto i : s){
        // 만일 숫자라면 하나씩 더한다
        if (i >= '0' && i <= '9'){
            temp += i;
        }
        // 숫자가 아닌데 변수가 비어있는경우 패스
        else if (temp == ""){
            continue;
        }
        // 숫자가 아닌데 변수가 비어있지 않은 경우
        else {
            // 맵에 해당 숫자가 없다면 넣는다
            if (hash.find(temp) == hash.end()){
                hash.insert({temp, 1});
            }
            else {
                // 있다면 갯수 증가
                hash[temp]++;
            }
            // 맵에 입력 후 변수 초기화
            temp = "";
        }
    }
    
    // 뱁의 백터화
    vector<pair<string, int>> storage;
    for (auto i : hash){
        storage.push_back(i);
    }
    
    // 등장 횟수로 정렬
    sort(storage.begin(), storage.end(), cmp);
    
    // 숫자를 정답 벡터에 
    for (auto i : storage){
        answer.push_back(stoi(i.first));
    }
    
    
    return answer;
}
