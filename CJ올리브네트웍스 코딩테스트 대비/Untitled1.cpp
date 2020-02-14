// 사전순으로 나열
//--> vector<string> 안에 string들 집어넣고!
//bool compare(string a, string b){
//	if(a.size() == b.size())	return a < b;
//	return a.size() < b.size();
//}
//--> 위에 있는 것처럼 a < b로 하면 사전순으로 알아서 된다 ㅋ
//--> 물론! sort( , , compare) 이렇게 해줘야 함 ㅋ

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool compare(string a, string b){
	return a > b;
}

int main(){
	vector<string> v;
	v.push_back("sadjklasjdl");
	v.push_back("xzczcaf");
	v.push_back("lslccc");
	
	sort(v.begin(), v.end(), compare);
	
	for(int i = 0 ; i < v.size() ; ++i){
		cout << v[i] << endl;
	}
	
	return 0;
}
