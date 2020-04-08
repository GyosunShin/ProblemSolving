// N < 10000 
// -10000 <= 각 원소의 값 <= 10000 

#include <cstdio> 
#include <algorithm>
#include <vector>

using namespace std;

int N;
int pan[10000];

vector<int> yang, um, ones;
bool zero_exist;
int ans;

bool comp(int a, int b){
	return a > b;
}

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &pan[i]);
		if(pan[i] > 1)	yang.push_back(pan[i]);
		else if(pan[i] == 1)	ones.push_back(1);
		else if(pan[i] == 0){
			zero_exist = true;
		}
		else	um.push_back(pan[i]);
	}
	
	sort(yang.begin(), yang.end());
	sort(um.begin(), um.end(), comp);
	
	ans += ones.size();
	
	if(yang.size() % 2 == 0){
		for(int i = 0 ; i < yang.size() ; i = i+2){
			ans += yang[i] * yang[i+1];
		}
	}
	else{
		ans += yang[0];
		for(int i = 1 ; i < yang.size() ; i = i+2){
			ans += yang[i] * yang[i+1];
		}
	}
	
	if(um.size() % 2 == 0){
		for(int i = 0 ; i < um.size() ; i = i+2){
			ans += um[i] * um[i+1];
		}
	}
	else{
		if(!zero_exist){
			ans += um[0];	
		}
		for(int i = 1 ; i < um.size() ; i = i+2){
			ans += um[i] * um[i+1];
		}
	}
	
	
	printf("%d", ans);
	
	return 0;
}
