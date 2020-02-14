#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> divide(string input){
    vector<string> in;
    vector<string> out;
    string u, v;
    for(int i = 0 ; i < input.size() ; ++i){
        if(in.size() > 0 && in.size() == out.size()){
            v += input.substr(i);
            break;
        }
        
        if(input[i] == '('){
            in.push_back(input.substr(i,1));
        }
        if(input[i] == ')'){
            out.push_back(input.substr(i,1));
        }
        u += input.substr(i,1);
    }    
    vector<string> ret;
    ret.push_back(u);   ret.push_back(v);
    return ret;
}

bool allright(string str){
    vector<string> picked;
    bool flag = true;
    for(int i = 0 ; i < str.size() ; ++i){
        if(str[i] == '('){
            picked.push_back(str.substr(i,1));
        }
        if(str[i] == ')'){
            if(picked.size() < 1){
                flag = false;
                break;
            }
            picked.pop_back();
        } 
    }
    if(flag)    return true;
    return  false;
}

bool isEmpty(string input){
    if(input == "") return true;
    return false;
}

string solve(string input){
    // 빈 문자열이면 바로 반환
    if(isEmpty(input)){
        return input;
    }
    
    // 일단 올바른 문자열인지 확인
    if(allright(input)){
        return input;
    }
    
    vector<string> ret = divide(input);
    string u = ret[0];  string v = ret[1];
        
    // u가 올바른 괄호 문자열일 경우
    if(allright(u)){
        u += solve(v);
        return u;
    }
    else{
        string ttmp; 
        ttmp += "(";
        ttmp += solve(v);
        ttmp += ")";
        
        int u_len = u.size();
        string tmp = u.substr(1, (u_len-2));
        for(int i = 0 ; i < tmp.size() ; ++i){
            if(tmp[i] == '(')  tmp[i] = ')';
            else if(tmp[i] == ')')  tmp[i] = '(';
        }
        ttmp += tmp;
        return ttmp;
    }
}

string solution(string p) {
    string answer;
    
    answer = solve(p);
    
    return answer;
}
