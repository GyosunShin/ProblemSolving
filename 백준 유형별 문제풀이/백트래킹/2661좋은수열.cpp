// 1<= N <= 80

#include <cstdio> 
#include <string>

#include <iostream>

using namespace std;

int N;

string answer = "33333333333333333333333333333333333333333333333333333333333333333333333333333333";

bool flag;

bool comp(string& a, string& b){

	int aSize = (int)a.size();	int bSize = (int)b.size();
	if(aSize == bSize){
		if(a.compare(b) <= 0)	return true;
		else	return false;
	}
	if(aSize < bSize)	return true;
}

bool check(string& input){
	
	// 1 <= size <= (input.size() / 2)
	int length = (int)input.size();
	
	for(int i = 1 ; i <= length / 2 ; ++i){
		string right = input.substr(length-i);
		string left = input.substr(length-i-i, i);
		if(right == left)	return false;
	}
	
	return true;
}

void dfs(string& input){
	
	if(flag)	return;
	
	if((int)input.size() == N){
		if(comp(input, answer)){
			flag = true;
			answer = input;
		}
		return;
	}
	
	for(int i = 1 ; i <= 3 ; ++i){
		input.push_back('0' + i);
		if(!check(input)){	// 안좋은 수열일 경우 
			input.pop_back();
			continue; 
		}
		dfs(input);
		input.pop_back();
	}
	
}

void solve(){
	string one = "1";	string two = "2";	string three = "3";
	dfs(one);
	dfs(two);
	dfs(three);
}

int main(){
	
	scanf("%d", &N);
	
	solve();
	
	printf("%s", answer.c_str());
	
	return 0;
}
