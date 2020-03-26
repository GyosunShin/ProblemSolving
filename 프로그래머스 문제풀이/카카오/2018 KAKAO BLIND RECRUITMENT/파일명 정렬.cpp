

// ���ϸ� <= 100�� 
// ���� ��ҹ���, ����, ����(" ), ��ħǥ(.), ���� ��ȣ(-")������ �̷���� �ִ�.
// ���ϸ��� �����ڷ� �����ϸ�, ���ڸ� �ϳ� �̻� �����ϰ� �ִ�.

// OUTPUT : �� ���ؿ� ���� ���ĵ� �迭�� ����Ѵ�. 

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




