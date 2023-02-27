#include <string>
#include <vector>
#include <set>

using namespace std;


vector<string> solution(vector<vector<int>> line) {

    vector<pair<long long, long long>> cross;
    
    for (int i = 0 ; i < line.size() ; i++){
        for (int j = i+1; j < line.size(); j++){
            long long a = (long long)line[i][0];
            long long b = (long long)line[i][1];
            long long e = (long long)line[i][2];  
            
            long long c = (long long)line[j][0];
            long long d = (long long)line[j][1];
            long long f = (long long)line[j][2];
            
            long long ad_bc = (a*d) - (b*c);
            
            if(ad_bc == 0)
                continue;
            
            
            long long bf_ed = (b*f) - (e*d);
            long long ec_af = (e*c) - (a*f);
            
            if (bf_ed % ad_bc || ec_af % ad_bc) 
                continue;
            long long x = bf_ed / ad_bc;
            long long y = ec_af / ad_bc;
            cross.push_back({x, y});
            
        }
    }

    long long min_x=1000000000000000;
    long long min_y=1000000000000000;
    long long max_x=-1000000000000000;
    long long max_y=-1000000000000000;

    for (const auto i : cross){
        if (max_x < i.first) max_x = i.first;
        if (min_x > i.first) min_x = i.first;
        if (max_y < i.second) max_y = i.second;
        if (min_y > i.second) min_y = i.second;
        
    }
    
    string row = string(max_x - min_x + 1, '.');
    vector<string> answer(max_y - min_y + 1, row);
    
    for (auto i : cross){
        answer[abs(i.second - max_y)][abs(i.first - min_x)] = '*';
    }
    
    return answer;
}