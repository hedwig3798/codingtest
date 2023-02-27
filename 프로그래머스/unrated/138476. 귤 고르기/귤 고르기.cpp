#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b){
    if (a.second == b.second) {
        return a.first > b.first;
    }
	return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> t;
    
    for (int i : tangerine){
        if (t.find(i) != t.end()){
            t[i] += 1;
        }
        else {
            t.insert({i, 1});
        }
    }
    
    vector<pair<int,int>> result(t.begin(), t.end());
    
    sort(result.begin(), result.end(), cmp);
    
    for (pair<int,int> j : result){
        if (k <= j.second){
            answer++;
            break;
        }
        else {
            k -= j.second;
            answer++;
        }
    }
    
    return answer;
}