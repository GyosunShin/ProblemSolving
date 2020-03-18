#include <iostream>
#include <string>

using namespace std;

string input;

int count[10];

int main(){
	cin >> input;
	
	for(int i = 0 ; i < input.size() ; ++i){
		count[input[i] - '0']++;
	}
	
	int tmp_sum = 0;
	for(int i = 0 ; i < 10 ; ++i){
		tmp_sum += count[i] * i;
	}
	
	if(count[0] == 0 || (tmp_sum % 3 != 0)){
		cout << "-1";
		return 0;	
	}
	
	
	
	string ans;
	
	for(int i = 9 ; i >= 0 ; --i){
		for(int j = 0 ; j < count[i] ; ++j){
			ans.push_back('0' + i);
		}
	}
	
	cout << ans;
	
	return 0;
}
