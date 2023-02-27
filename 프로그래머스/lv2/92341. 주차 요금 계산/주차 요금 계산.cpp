#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

void pprint(vector<string> i){
    for (string t : i){
        printf("%s ", t.c_str());
    }
    printf("\n");
}

void ppprint(vector<vector<string>> i){
    for (vector<string> t : i){
        pprint(t);
    }
    printf("\n");
}

vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }
 
    return result;
}

bool cmp(vector<string> a, vector<string> b){
    return stoi(a[0]) < stoi(b[0]);
}

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

    for (string i : records){
        
        vector<string>temp;
        temp = split(i, ' ');
        int find_flag = 0;
        for (vector<string> &f : table){
            if (f[0] == temp[1]){
                if (f[2].compare("IN") == 0){
                    f[2] = "OUT";
                    f[1] = to_string(stoi(f[1]) + get_time_diff(f[3], temp[0]));
                }
                else if (f[2] == "OUT"){
                    f[2] = "IN";
                    f[3] = temp[0];
                }
                find_flag = 1;
                break;
            }
        }
        if (find_flag == 0){
            vector<string> ttemp;
            ttemp.push_back(temp[1]);
            ttemp.push_back("0");
            ttemp.push_back("IN");
            ttemp.push_back(temp[0]);
            table.push_back(ttemp);
        }
        // ppprint(table);
    }
    sort(table.begin(), table.end(), cmp);
    
    for (vector<string> &i : table){

        if (i[2] == "IN"){
            i[1] = to_string(stoi(i[1]) + get_time_diff(i[3], "23:59"));
        }

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
    //ppprint(table);
    
    return answer;
}