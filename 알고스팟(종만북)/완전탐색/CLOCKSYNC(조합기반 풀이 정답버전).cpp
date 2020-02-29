#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int pan[16];

vector<int> picked;
vector<int> switches[10];

int forward(int input){
	switch(input){
		case 12:	return 3;
		case 3:	return 6;
		case 6:	return 9;
		case 9:	return 12;
		default:	return -1;
	}
}
int prev(int input){
	switch(input){
		case 12:	return 9;
		case 3:	return 12;
		case 6:	return 3;
		case 9:	return 6;
		default:	return -1;
	}
}
bool check(){
	bool tmp_flag = true;
	for(int i = 0 ; i < 16 ; ++i){
		if(pan[i] != 12){
			tmp_flag = false;
			break;
		}
	}
	return tmp_flag;
}

int dfs(int idx){
	if(check()){
		return 0;
	}
	if(idx == 10)	return 9999;
	
	int tmp_ret = 0x7fffffff;
	
	for(int cnt = 0 ; cnt < 4 ; ++cnt){
		// idx스위치를 cnt만큼 이용한다.
		for(int z = 0 ; z < cnt ; ++z){
			for(int k = 0 ; k < switches[idx].size() ; ++k){
				int target = switches[idx][k];
				pan[target] = forward(pan[target]);
			}
		}
		
		tmp_ret = min(tmp_ret, cnt + dfs(idx+1));
		
		for(int z = 0 ; z < cnt ; ++z){
			for(int k = 0 ; k < switches[idx].size() ; ++k){
				int target = switches[idx][k];
				pan[target] = prev(pan[target]);
			}
		}		
	}
	
	return tmp_ret;
}


int main(){
	scanf("%d", &T);
	
	switches[0].push_back(0);	switches[0].push_back(1);	switches[0].push_back(2);
	switches[1].push_back(3);	switches[1].push_back(7);	switches[1].push_back(9);	switches[1].push_back(11);
	switches[2].push_back(4);	switches[2].push_back(10);	switches[2].push_back(14);	switches[2].push_back(15);
	switches[3].push_back(0);	switches[3].push_back(4);	switches[3].push_back(5);	switches[3].push_back(6);	switches[3].push_back(7);
	switches[4].push_back(6);	switches[4].push_back(7);	switches[4].push_back(8);	switches[4].push_back(10);	switches[4].push_back(12);
	switches[5].push_back(0);	switches[5].push_back(2);	switches[5].push_back(14);	switches[5].push_back(15);
	switches[6].push_back(3);	switches[6].push_back(14);	switches[6].push_back(15);
	switches[7].push_back(4);	switches[7].push_back(5);	switches[7].push_back(7);	switches[7].push_back(14);	switches[7].push_back(15);
	switches[8].push_back(1);	switches[8].push_back(2);	switches[8].push_back(3);	switches[8].push_back(4);	switches[8].push_back(5);
	switches[9].push_back(3);	switches[9].push_back(4);	switches[9].push_back(5);	switches[9].push_back(9);	switches[9].push_back(13);
	
	for(int z = 1 ; z <= T ; ++z){	
		for(int i = 0 ; i < 16 ; ++i){
			scanf("%d", &pan[i]);
		}
		
		if(check()){
			printf("0\n");
			continue;
		}
		
		int ans = dfs(0);
		if(ans >= 9999)	ans = -1;
		
		printf("%d\n", ans);
	}
	return 0;
}
