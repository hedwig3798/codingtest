#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    // 등대의 루트맵
    vector<set<int>> route (lighthouse.size() + 2);
    
    // 루트맵 작성
    for (auto i : lighthouse){
        route[i[0]].insert(i[1]);
        route[i[1]].insert(i[0]);
    }
    
    // 모든 등대를 순회하는 것을 반복
    for (int end = 0; end != 1;){
        // 반복 플래그
        end = 1;
        // 모든 등대 순회
        for (int i = 1;  i < route.size() ; i++){
            // 아직 연결되지 않은 노드가 있는 경우 반복을 다시 한다
            if (route[i].size() != 0)
                end = 0;
            // 연결된 노드가 하나밖에 없는경우
            if (route[i].size() == 1){
                // 이 때 빛을 밝히므로
                answer++;
                // 그 노드에 연결된 부모 노드 번호를 저장 (원소가 하나밖에 없으므로 이런식으로 가져올 수 있다.)
                int temp = *route[i].begin();
                // 해당 부모 노드에 연결되어 있는 다른 노드들에서 부모 노드를 제거
                for (int j : route[temp]){
                    route[j].erase(temp);
                }
                // 해당 노드 제거
                route[i].clear();
                // 부모 노드 
                route[temp].clear();
            }
        }
    }
    
    return answer;
}
