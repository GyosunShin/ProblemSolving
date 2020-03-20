//1. �Է��� �� ���ڿ��� ���, �� ���ڿ��� ��ȯ�մϴ�. 
//2. ���ڿ� w�� �� "�������� ��ȣ ���ڿ�" u, v�� �и��մϴ�. ��, u�� "�������� ��ȣ ���ڿ�"�� �� �̻� �и��� �� ����� �ϸ�, v�� �� ���ڿ��� �� �� �ֽ��ϴ�. 
//3. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�" �̶�� ���ڿ� v�� ���� 1�ܰ���� �ٽ� �����մϴ�. 
//  3-1. ������ ��� ���ڿ��� u�� �̾� ���� �� ��ȯ�մϴ�. 
//4. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�"�� �ƴ϶�� �Ʒ� ������ �����մϴ�. 
//  4-1. �� ���ڿ��� ù ��° ���ڷ� '('�� ���Դϴ�. 
//  4-2. ���ڿ� v�� ���� 1�ܰ���� ��������� ������ ��� ���ڿ��� �̾� ���Դϴ�. 
//  4-3. ')'�� �ٽ� ���Դϴ�. 
//  4-4. u�� ù ��°�� ������ ���ڸ� �����ϰ�, ������ ���ڿ��� ��ȣ ������ ����� �ڿ� ���Դϴ�. 
//  4-5. ������ ���ڿ��� ��ȯ�մϴ�.

// OUTPUT
// �������� ��ȣ ���ڿ� p�� �Ű������� �־��� ��, �־��� �˰����� ������ �ùٸ� ��ȣ ���ڿ��� ��ȯ�� ����� return

#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check(string& input){
	
	vector<char> tmp;
	
	for(int i = 0 ; i < input.size() ; ++i){
		char cur = input[i];
		
		if(cur == ')'){
			if(tmp.size() > 0 && tmp.back() == '('){
				tmp.pop_back();
			}
			else{
				tmp.push_back(cur);
			}
		}
		else{
			tmp.push_back(cur);
		}
		
	}
	
	if(tmp.size() == 0)	return true;
	return false;
}


string solve(string& str){
		
	if(str.size() == 0)	return str;
	
	if(check(str))	return str;
	
	int cnt1 = 0;	int cnt2 = 0;
	int idx = -1;
	for(int i = 0 ; i < str.size() ; ++i){
		if(cnt1 == cnt2 && cnt1 > 0 && cnt2 > 0){
			idx = i;
			break;
		}
		if(str[i] =='(')	++cnt1;	
		if(str[i] ==')')	++cnt2;
	}
	// idx�� ���ڿ� v�� ���� �ε���
	string u;
	string v;
	if(idx == -1){
		u = str;
		v = "";	
	}
	else{
		u = str.substr(0, idx);
		v = str.substr(idx);
	}
	
//	cout << "U : " << u << endl << "V : " << v << endl;
		
	if(check(u)){	// u�� �ùٸ� ���ڿ��̶�� 
		// ���ڿ� v�� ���� 1�ܰ���� �ٽ� �����մϴ�. 
  		// 3-1. ������ ��� ���ڿ��� u�� �̾� ���� �� ��ȯ�մϴ�. 
  		u += solve(v);
		return u;
	}
	else{	// u�� �ùٸ� ���ڿ��� �ƴ϶�� 
		string tmp = "(";
		tmp += solve(v);
		tmp += ")";
		//  u�� ù ��°�� ������ ���ڸ� �����ϰ�, ������ ���ڿ��� ��ȣ ������ ����� �ڿ� ���Դϴ�. 
		u.pop_back();
		u = u.substr(1);
		for(int i = 0 ; i < u.size() ; ++i){
			if(u[i] == '(')	u[i] = ')';
			else if(u[i] == ')')	u[i] = '(';
		}
		tmp += u;
		return tmp;
	}
	
}

string solution(string p) {
    
    return solve(p);
}

