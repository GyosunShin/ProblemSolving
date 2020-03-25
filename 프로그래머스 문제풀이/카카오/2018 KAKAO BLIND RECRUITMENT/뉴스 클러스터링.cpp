
// ��ī�� ���絵 : ������ ũ�� / ������ ũ�� 

// ���� A�� ���� B�� ��� �������� ��쿡�� �������� ���ǵ��� ������ ���� J(A, B) = 1�� �����Ѵ�.

// ��������
// ������ : min
// ������ : max

// 2 <= ���ڿ��� ���� <= 1000

// �빮�ڿ� �ҹ����� ���̴� ����

// OUTPUT : 65536�� ���� �Ŀ� �Ҽ��� �Ʒ��� ������ �����θ� ����Ѵ�.


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

vector<string> a;
vector<string> b;

map<string, int> ma;
map<string, int> mb;

int hap, gyo;

bool alpha(char& input){
	
	if(('a' <= input && input <= 'z') || ('A' <= input && input <= 'Z'))	return true;
	return false;
}

void div(string& s1, string& s2){
	
	for(int i = 0 ; i < s1.size()-1 ; ++i){
		
		string tmp;
		tmp += s1.substr(i, 2);
		if(!alpha(tmp[0]) || !alpha(tmp[1]))	continue;
		a.push_back(tmp);
		
	}
	
	for(int i = 0 ; i < s2.size()-1 ; ++i){
		
		string tmp;
		tmp += s2.substr(i, 2);
		if(!alpha(tmp[0]) || !alpha(tmp[1]))	continue;
		b.push_back(tmp);
		
	}	
	
	
}

void check(){
	
	for(int i = 0 ; i < a.size() ; ++i){
		ma[a[i]] += 1;
	}

	for(int i = 0 ; i < b.size() ; ++i){
		mb[b[i]] += 1;
	}			
	
}

void solve(){
	
	map<string, int>::iterator it;
	for(it = ma.begin() ; it != ma.end() ; ++it){
		
		string cur = it->first;
		int cur_cnt = it->second;
		
		map<string, int>::iterator itt;	
		itt = mb.find(cur);
		
		if(itt == mb.end()){
			hap += cur_cnt;
		}
		else{
			gyo += min(cur_cnt, itt->second);
			hap += max(cur_cnt, itt->second);
		}
			
	}
	
	for(it = mb.begin() ; it != mb.end() ; ++it){
		
		string cur = it->first;
		int cur_cnt = it->second;
		
		map<string, int>::iterator itt;	
		itt = ma.find(cur);
		
		if(itt == ma.end()){
			hap += cur_cnt;
		}
		
	}
	
}


int solution(string str1, string str2) {
	
	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
	
	
	div(str1, str2);
	
	check();
	
	solve();
	
//	cout << "GYO : " << gyo << " / " << "HAP : " << hap << endl;
	
	int ans;
	
	if(gyo == 0 && hap == 0)	return 65536;
	
	ans = (int)((gyo / (double)hap) * 65536);
	
	return ans;
}







