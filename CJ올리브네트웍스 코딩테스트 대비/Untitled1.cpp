// ���������� ����
//--> vector<string> �ȿ� string�� ����ְ�!
//bool compare(string a, string b){
//	if(a.size() == b.size())	return a < b;
//	return a.size() < b.size();
//}
//--> ���� �ִ� ��ó�� a < b�� �ϸ� ���������� �˾Ƽ� �ȴ� ��
//--> ����! sort( , , compare) �̷��� ����� �� ��

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
