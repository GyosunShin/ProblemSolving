

// 파일명 <= 100자 
// 영문 대소문자, 숫자, 공백(" ), 마침표(.), 빼기 부호(-")만으로 이루어져 있다.
// 파일명은 영문자로 시작하며, 숫자를 하나 이상 포함하고 있다.

// OUTPUT : 위 기준에 따라 정렬된 배열을 출력한다. 

// HEAD, NUMBER, TAIL

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct INFO{
	string HEAD, NUMBER, TAIL;
	int idx;
};

vector<INFO> vs;
vector<string> answer;

bool comp(INFO& a, INFO& b){
	
	string aH = a.HEAD;
	string bH = b.HEAD;
	transform(aH.begin(), aH.end(), aH.begin(), ::tolower);
	transform(bH.begin(), bH.end(), bH.begin(), ::tolower);
	
	int ai, bi;
	ai = stoi(a.NUMBER);
	bi = stoi(b.NUMBER);
	
	if(aH == bH && ai == bi)	return a.idx < b.idx;
	if(aH == bH)	return ai < bi;
	return aH < bH;
	
}

vector<string> solution(vector<string> files) {

	for(int i = 0 ; i < files.size() ; ++i){
		string cur_str = files[i];
		int Nidx;
		for(int j = 0 ; j < cur_str.size() ; ++j){
			if('0' <= cur_str[j] && cur_str[j] <= '9'){
				Nidx = j;
				break;
			}
		}
		
		string head = cur_str.substr(0, Nidx);
		string number;
		string tail;
		
		int Tidx = -1;
		for(int j = Nidx ; j < cur_str.size() ; ++j){
			if(!('0' <= cur_str[j] && cur_str[j] <= '9')){
				Tidx = j;
				break;	
			}
		}
		
		if(Tidx == -1){
			number = cur_str.substr(Nidx);
			tail = "";
		}
		else{
			number = cur_str.substr(Nidx, Tidx-Nidx);
			tail = cur_str.substr(Tidx);
		}
		
		INFO cur;
		cur.HEAD = head;
		cur.NUMBER = number;
		cur.TAIL = tail;
		cur.idx = i;
		
//		cout << head << " / " << number << " / " << tail << endl;
		
		vs.push_back(cur);
	}
	
	sort(vs.begin(), vs.end(), comp);
	
	for(int i = 0 ; i < vs.size() ; ++i){
		answer.push_back(files[vs[i].idx]);
	}

    return answer;
}




