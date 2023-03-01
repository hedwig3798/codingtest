#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    // 보석의 정보를 담을 맵
    // 전체 보석의 정보가 있는 맵
    map<string, int> all_j;
    // 특정 구간에 있는 보석의 정보를 담을 맵
    map<string, int> part_j;
    
    // 투 포인터 알고리즘을 위한 변수
    int start = 0;
    int end  = 0;
    
    // 전체 보석 정보를 담음
    for (auto i : gems){
        all_j[i] += 1; 
    }
    
    // 정답의 최대치 입력 ([1, n])
    answer.push_back(1);
    answer.push_back(gems.size());
    
    // 투 포인터 알고리즘 시작
    // 두 지점 모두 끝까지 도달 할 때까지 반복
    for (;end != gems.size() || start != gems.size();){
        // end가 끝이 아니면서 구간의 보석의 갯수가 전체 갯수가 아닌 경우
        if (part_j.size() != all_j.size() && end != gems.size()){
            // 구간 보석 맵에 정보를 담고 지점을 움직임
            part_j[gems[end]] += 1;
            end++;
        }
        // 아니라면 start 지점을 움직이고 구간 맵에서 정보를 지움
        else {
            part_j[gems[start]] -= 1;
            if (part_j[gems[start]] == 0){
                part_j.erase(gems[start]);
            }
            start++;
        }
        // 위 과정 후에 해당 전체와 구간에 보석의 갯수가 같은 경우 정답과 비교하여 더 작은 쪽을 택함
        // 만일 두 구간이 모두 같은 경우 시작점이 작은 것을 택하므로 비교하지 
        if (answer[1] - answer[0] > end - start - 1 && part_j.size() == all_j.size()){
            answer[1] = end;
            answer[0] = start + 1;
        }
    }

    return answer;
}
