#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> map;
vector<int> picked;

int ans;

bool check(int input){
	int tmp = sqrt(input);
	for(int i = 2 ; i <= tmp ; ++i){
		if(input % i == 0)	return  false;
	}
	return true;
}

void dfs(int start){
	if(picked.size() == 3){
		int tmp_sum = 0;
		for(int i = 0 ; i < picked.size() ; ++i){
//			cout << picked[i] << " / ";
			tmp_sum += picked[i];
		}
//		cout << endl << "TMP_SUM : " << tmp_sum << endl;
		if(check(tmp_sum)){
//			cout << "SUCCEED!!" << endl;
			++ans;
		}	
		return;
	}
	
	for(int i = start ; i < map.size() ; ++i){
		picked.push_back(map[i]);
		dfs(i + 1);
		picked.pop_back();		
	}
}

int solution(vector<int> nums) {
	map = nums;
	dfs(0);	
	return ans;
}




