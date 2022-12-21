#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

// 디버깅용 함수
void pprint(vector<string> i){
    for (string t : i){
        printf("%s ", t.c_str());
    }
    printf("\n");
}

// 디버깅용 함수
void ppprint(vector<vector<string>> i){
    for (vector<string> t : i){
        pprint(t);
    }
    printf("\n");
}

// 문자열 슬라이싱 함수
vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }
 
    return result;
}

// sort 함수에 사용될 비교 함수
bool cmp(vector<string> a, vector<string> b){
    return stoi(a[0]) < stoi(b[0]);
}

// 문자열로 이루어진 시간 계산 함수
int get_time_diff(string in, string out){
    vector<string> s_in;
    vector<string> s_out;
        
    s_in = split(in, ':');
    s_out = split(out, ':');
    
    int h = stoi(s_out[0]) - stoi(s_in[0]);
    int m = stoi(s_out[1]) - stoi(s_in[1]);
    
    if (m < 0){
        m += 60;
        h -= 1;
    }
    
    return (h * 60) + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<vector<string>> table;
    
    // 메인 반복문
    for (string i : records){
        // 임시 백터를 생성하여 records 내용을 벡터화
        vector<string>temp;
        temp = split(i, ' ');
        
        // 탐색에 사용될 플래그
        int find_flag = 0;
        
        // 자체 데이터 테이블을 생성하는 과정
        for (vector<string> &f : table){
            // 해당 번호의 차가 테이블에 있는경우
            if (f[0] == temp[1]){
                // 출차의 경우
                if (f[2].compare("IN") == 0){
                    f[2] = "OUT";
                    f[1] = to_string(stoi(f[1]) + get_time_diff(f[3], temp[0]));
                }
                // 입차의 경우
                else if (f[2] == "OUT"){
                    f[2] = "IN";
                    f[3] = temp[0];
                }
                find_flag = 1;
                break;
            }
        }
        // 테이블에 해당 번호의 자동차가 없는경우 테이블에 데이터 입력
        if (find_flag == 0){
            vector<string> ttemp;
            ttemp.push_back(temp[1]);
            ttemp.push_back("0");
            ttemp.push_back("IN");
            ttemp.push_back(temp[0]);
            table.push_back(ttemp);
        }
    }
    // 제한 사항에 맞게 테이블 데이터를 자동차 번호순으로 정렬
    sort(table.begin(), table.end(), cmp);
    
    // 테이블을 순회하면서 요금 구하기
    for (vector<string> &i : table){
        // 아직도 입차중인 경우 23:59에 출차 했다는 가정이므로 시간 계산
        if (i[2] == "IN"){
            i[1] = to_string(stoi(i[1]) + get_time_diff(i[3], "23:59"));
        }
        
        // 요금 구하기
        int prise = 0;
        float time = stof(i[1]);
        float base = fees[0];
        float unit = fees[2];
        prise += fees[1];
        if (stoi(i[1]) > fees[0]){
            prise += ceil((time - base) / unit) * fees[3];
        }
        answer.push_back(prise);
    }
    return answer;
}
