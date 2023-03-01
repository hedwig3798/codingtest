#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 정렬 백터
bool cmp_map(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    // 각 장르에 대한 플레이 횟수가 담길 맵
    map<string, int> g;
    // 각 장르에 대하 가장 높은 2가지 음악을 담을 맵
    map<string, vector<pair<int, int>>> p;
    
    // 플레이된 모든 음악에 대해 반복
    for (int i = 0 ; i < plays.size() ; i++){
        // 만일 해당 장르의 음악이 맵에 있다면
        if (g.find(genres[i]) != g.end()){
            // 합계 맵에 플에이 수를 더함
            g[genres[i]] += plays[i];
            
            // 첫 음악보다 크다면 교체 후 원래 있던 음악을 아래로 내림
            if (p[genres[i]][0].second < plays[i]){
                pair<int, int> temp = p[genres[i]][0];
                p[genres[i]][0] = {i, plays[i]};
                p[genres[i]][1] = temp;
            }
            // 두번째 음악보다 크다면 교체
            else if (p[genres[i]][1].second < plays[i]){
                p[genres[i]][1] = {i, plays[i]};
            }
        }
        // 해당 장르의 음악이 처음이라면
        else {
            // 합계 맵에 입력
            g.insert({genres[i], plays[i]});
            // 음악 맵에 입력 후 첫 음악으로 넣음
            p.insert({genres[i], vector<pair<int, int>>(2, {0, 0})});
            p[genres[i]][0] = {i, plays[i]};
        }
    }
    
    // 정렬을 위한 벡터 생성
    vector<pair<string, int>>temp;
    for (auto i : g){
        temp.push_back(i);
    }
    
    // 정렬
    sort(temp.begin(), temp.end(), cmp_map);
    
    // 벡터 크기 만큼 반복하며 조건에 맞는 음악 입력
    for (int i = 0 ; i < temp.size() ; i++){
        // 첫 음악 입력
        answer.push_back(p[temp[i].first][0].first);
        // 만일 두번째 음악이 있다면 
        if (p[temp[i].first][1].second != 0)
            answer.push_back(p[temp[i].first][1].first);
    }
    
    return answer;
}
