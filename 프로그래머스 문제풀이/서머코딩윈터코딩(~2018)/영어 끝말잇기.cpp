// 가장 먼저 탈락하는 사람의 번호와 그 사람이 자신의 몇 번째 차례에 탈락하는지를 구해서 return
// [ 번호, 차례 ] 형태로 return

#include <string>
#include <vector>
#include <iostream>
#include <set> 

using namespace std;
set<string> s;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int who = 0;
    int order = 0;
    
    for(int i = 0 ; i < words.size() ; ++i){
		set<string>::iterator it;
		it = s.find(words[i]);
		if(it == s.end()){
			s.insert(words[i]);
			if(i != 0){
				if(words[i-1][words[i-1].size() - 1] != words[i][0]){
					who = (i % n) + 1;
					order = (i / n) + 1;
					break;		
				}
			}
		}
		else{
			who = (i % n) + 1;
			order = (i / n) + 1;
			break;
		}
    }
    answer.push_back(who);
    answer.push_back(order);
    return answer;
}
