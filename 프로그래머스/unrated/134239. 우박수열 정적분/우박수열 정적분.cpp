#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> kol;
    vector<double> vec;
    double result = 0.0;
    
    while(1){
        if (k == 1){
            kol.push_back(k);
            break;
        }
        kol.push_back(k);
        if (k%2 == 0){
            k = k/2;
        }
        else{
            k = k*3 + 1;
        }
    }
    
    for (vector<int> r : ranges){
        
        if ((r[0] - r[1]) >= kol.size()){
            answer.push_back(-1);
            continue;
        }
        
        auto fornt = kol.begin() + r[0];
        auto back = kol.end() + r[1];
        result = 0.0;
        vec = vector(fornt, back);
        
        for (int i = 0; i < vec.size()-1; i++){
            if (vec[i] < vec[i+1]){
                result += vec[i] + ((vec[i+1]-vec[i]) / 2);
            }
            else{
                result += vec[i+1] + ((vec[i]-vec[i+1]) / 2);
            }
        }
        answer.push_back(result);
    }

    
    
    
    return answer;
}