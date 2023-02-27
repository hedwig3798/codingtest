#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp_map(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> g;
    map<string, vector<pair<int, int>>> p;
    for (int i = 0 ; i < plays.size() ; i++){
        if (g.find(genres[i]) != g.end()){
            g[genres[i]] += plays[i];
            
            if (p[genres[i]][0].second < plays[i]){
                pair<int, int> temp = p[genres[i]][0];
                p[genres[i]][0] = {i, plays[i]};
                p[genres[i]][1] = temp;
            }
            else if (p[genres[i]][1].second < plays[i]){
                p[genres[i]][1] = {i, plays[i]};
            }
            
        }
        else {
            g.insert({genres[i], plays[i]});
            p.insert({genres[i], vector<pair<int, int>>(2, {0, 0})});
            p[genres[i]][0] = {i, plays[i]};
        }
    }
    
    vector<pair<string, int>>temp;
    for (auto i : g){
        temp.push_back(i);
    }
    
    
    sort(temp.begin(), temp.end(), cmp_map);
    
    // for (auto i : temp){
    //     cout << i.first << ' ' << p[i.first][0].first << ' ' << p[i.first][0].second << endl;
    // }
    
    for (int i = 0 ; i < temp.size() ; i++){
        answer.push_back(p[temp[i].first][0].first);
        if (p[temp[i].first][1].second != 0)
            answer.push_back(p[temp[i].first][1].first);
    }
    
    return answer;
}