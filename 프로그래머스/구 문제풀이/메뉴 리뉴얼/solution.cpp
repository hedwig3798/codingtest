#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// 메뉴 정보를 담을 map
map <string, int> table;

// 정렬함수
bool cmp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

// DFS 함수
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
    // 메뉴 가짓수를 DFS를 통해서 가능한 모든 가짓수 찾기
    for (string menu : orders){
        sort(menu.begin(), menu.end());
        for (int count : course){
            string temp = "";
            temp.resize(count);
            insertMap(menu, 0, 0, temp);
        }
    }
    
    // 2번 이상 시킨것 필터링
    vector<pair<string, int>> result;
    for (auto i : table){
        if (i.second < 2)
            continue;
        else
            result.push_back(i);
    }
    // 시킨 횟수에 따라 정렬
    sort(result.begin(), result.end(), cmp);
    
    // 시킨 갯수와 세트 메뉴의 갯수가 일치하는 경우 필터링
    for (auto i : course){
        int max = 0;
        for (auto j : result){
            if (j.first.length() != i) continue;
            // 최대치인 경우 가져오기
            // 여러개인 경우 또한 고려
            if (max == 0 || max == j.second) {
                max = j.second;
                answer.push_back(j.first);
            }
            else break;
        }
        
    }
    // 제한사항에 맞게 
    sort(answer.begin(), answer.end());
    return answer;
}
