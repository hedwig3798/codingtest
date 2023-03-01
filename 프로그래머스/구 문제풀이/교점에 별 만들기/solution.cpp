#include <string>
#include <vector>

using namespace std;


vector<string> solution(vector<vector<int>> line) {
    // 교점 저장 백터
    vector<pair<long long, long long>> cross;
    
    // 교점 구하는 루프
    for (int i = 0 ; i < line.size() ; i++){
        for (int j = i+1; j < line.size(); j++){
            // 보기 편하게 변수 이름 지정
            long long a = (long long)line[i][0];
            long long b = (long long)line[i][1];
            long long e = (long long)line[i][2];  
            
            long long c = (long long)line[j][0];
            long long d = (long long)line[j][1];
            long long f = (long long)line[j][2];
            
            // 평행하거나 같은 경우
            long long ad_bc = (a*d) - (b*c);
            
            // 이런 방식으로 한줄 if문 사용하니 깔끔해 진 듯 하다
            if(ad_bc == 0)
                continue;
            
            // 교점에 정수가 없는 경우
            long long bf_ed = (b*f) - (e*d);
            long long ec_af = (e*c) - (a*f);
            if (bf_ed % ad_bc || ec_af % ad_bc) 
                continue;
            
            // 위 조건을 만족하는 정수로만 이루어진 교점을 저장
            long long x = bf_ed / ad_bc;
            long long y = ec_af / ad_bc;
            cross.push_back({x, y});
            
        }
    }
    
    // 임의 max, min값 지정. 제한사항 상 이 값 이상으로 나올 수가 없다.
    long long min_x=1000000000000000;
    long long min_y=1000000000000000;
    long long max_x=-1000000000000000;
    long long max_y=-1000000000000000;
  
    // 실제 max, min값 구하기
    for (const auto i : cross){
        if (max_x < i.first) max_x = i.first;
        if (min_x > i.first) min_x = i.first;
        if (max_y < i.second) max_y = i.second;
        if (min_y > i.second) min_y = i.second;
        
    }
    
    // . 으로 이루어진 백터 만들기
    string row = string(max_x - min_x + 1, '.');
    vector<string> answer(max_y - min_y + 1, row);
    
    // 교점 위치에 * 
    for (auto i : cross){
        answer[abs(i.second - max_y)][abs(i.first - min_x)] = '*';
    }
    
    return answer;
}
