// 정해진 횟수만큼 숫자판을 교환했을 때 받을 수 있는 가장 큰 금액을 계산해보자.

#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int T, map, num, len;
int maax = -1 * 0x7fffffff;
string str;

vector<pair<int, int> > picked;

int calc(string input){
	int ret = 0;
	int len = input.size();
	
	for(int i = 0 ; i < len ; ++i){
		int flag = pow(10, len - 1 - i);
		ret += flag * (input[i] - '0');
	}
	
	return ret;
}

void dfs(){
	if(picked.size() == num){
		string tmp_str = str;
		for(int i = 0 ; i < picked.size() ; ++i){
			swap(tmp_str[picked[i].first], tmp_str[picked[i].second]);
		}
		int tmp_sum = calc(tmp_str);
		if(maax < tmp_sum)	maax = tmp_sum;
		return;
	}
	
	for(int i = 0 ; i < len ; ++i){
		for(int j = i+1 ; j < len ; ++j){
			if((picked.size() == 0)){
				picked.push_back(make_pair(i, j));
				dfs();
				picked.pop_back();
			}
			else{
				if((i == picked.back().first && j >= picked.back().second) || (i > picked.back().first)){
					picked.push_back(make_pair(i, j));
					dfs();
					picked.pop_back();		
				}
			}
		}
	}
}

void solve(){
	str = to_string(map);
	len = str.size();
	dfs();
}

int main(){
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		maax = -1 * 0x7fffffff;
		picked.clear();
		scanf("%d %d", &map, &num);
		solve();
		printf("#%d %d\n", (z+1), maax);
	}
	return 0;
}
