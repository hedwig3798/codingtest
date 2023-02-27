#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;
   
vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string tmp;
 
    while (getline(ss, tmp, delimiter)) result.push_back(tmp);
 
    return result;
}



vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<string, vector<int>> m;
    vector<vector<string>> c (4, vector<string>(2, "-"));
    
    for (string i : info){
        vector<string> temp = split(i, ' ');
        
        for (int i  = 0 ; i < 4 ; i++){
            c[i][0] = temp[i];
        }

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
    
    for (auto &i : m){
        sort(i.second.begin(), i.second.end());
    }
    

    for (string i : query){
        vector<string> temp = split(i, ' ');
        string str = temp[0] + temp[2] + temp[4] + temp[6];
        auto itr = lower_bound(m[str].begin(), m[str].end(), stoi(temp[7]));
        answer.push_back(m[str].size() - (itr - m[str].begin()));

    }
    
    return answer;
}