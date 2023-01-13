#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// C++에는 split 함수가 없으므로 구현함
vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string tmp;
 
    while (getline(ss, tmp, delimiter)) result.push_back(tmp);
 
    return result;
}



vector<int> solution(vector<string> info, vector<string> query) {
    // 미리 정갑 벡터의 크기를 정해 놓음
    vector<int> answer;
    // 시간복잡도를 줄이기 위해 해당 자료구조 사용 ( 조건, 조건에 맞는 응시자의 점수 벡터 )
    unordered_map<string, vector<int>> m;
    // 응시자 정보를 담을 벡터
    vector<vector<string>> c (4, vector<string>(2, "-"));
    
    // 응시자 정보를 입력
    for (string i : info){
       
        vector<string> temp = split(i, ' ');
        
        // 응시자 정보를 벡터에 저장
        for (int i  = 0 ; i < 4 ; i++){
            c[i][0] = temp[i];
        }
        // 해당 응시자 에게서 가능한 모든 경우의 수를 골라서 map에 저장
        string t1, t2, t3 ,t4;
        for (int i = 0 ; i < 2 ; i++){
            t1 = c[0][i];
            for (int j = 0 ; j < 2 ; j++){
                t2 = c[1][j];
                for (int k = 0 ; k < 2 ; k++){
                    t3 = c[2][k];
                    for (int w = 0 ; w < 2 ; w++){
                        t4 = c[3][w];
                        m[t1 + t2 + t3 + t4].push_back(stoi(temp[4]));
                    }
                }
            }
        }
    }
    // 응시자 map의 점수를 정렬
    for (auto &i : m){
        sort(i.second.begin(), i.second.end());
    }

    for (string i : query){
        vector<string> temp = split(i, ' ');
        // 쿼리문에서 필요한 정보만 string형태로 저장
        string str = temp[0] + temp[2] + temp[4] + temp[6];
        // lower_bound함수를 사용하여 어느 곳에 최소치가 저장 되어 있는지 확인
        auto itr = lower_bound(m[str].begin(), m[str].end(), stoi(temp[7]));
        // 미리 정렬되어 있으므로 해당 부분에서 나머지 까지의 벡터의 크기를 구하여 정답에 입력.
        answer.push_back(m[str].size() - (itr - m[str].begin()));
    }
    
    return answer;
}
