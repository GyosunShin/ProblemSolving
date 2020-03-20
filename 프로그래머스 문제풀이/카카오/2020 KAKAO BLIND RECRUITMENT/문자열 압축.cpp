#include <string>
#include <vector>
#include <iostream>

// 가장 짧은 것의 길이를 return

using namespace std;

int solution(string s) {
    int answer = 0x7fffffff;
    int strlen = s.length();
    
    // 1 ~ strlen길이까지 가능
    for(int z = 1 ; z <= strlen ; ++z){
        string ret = "";
        vector<string> divided;
        int idx = 0;
        while(idx < strlen){
            if(idx + z >= strlen){
                divided.push_back(s.substr(idx));    
                break;
            }
            divided.push_back(s.substr(idx, z));
            idx += z;
        }
        
        string target = divided[0];
        int num = 0;
        for(int i = 0 ; i < divided.size() ; ++i){
            if(divided[i] == target){
                ++num;    
            }
            if(divided[i] != target){
                if(num > 1){
                    ret += to_string(num);
                }
                ret += divided[i-1];
                target = divided[i];
                num = 1;
            }
            if(i == divided.size() - 1){
                if(divided[i-1] != divided[i]){
                    ret += divided[i];
                    break;    
                }
                if(num > 1){
                    ret += to_string(num);
                }
                ret += divided[i-1];
                break;
            }
        }
        // cout << "[" << ret << "]" << endl;
        if(answer > ret.size())    answer = ret.size();
    }
    
    
    return answer;
}
