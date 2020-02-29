#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int pan[16];
int howmany[10];
int cache[10][30];

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

int solve(int who, int idx){
	printf("WHO : %d / IDX : %d\n", who, idx);
//	for(int i = 0 ; i < 16 ; ++i)	printf("%d ", pan[i]);
//	printf("\n");
	if(idx == 29 && !check())	return 0x7fffffff;
	
	int& ret = cache[who][idx];
	if(ret != -1)	return ret;
	
	if(check()){
		printf("DONE!\n");
		return ret = 0;
	}
	
	int tmp_min = 0x7fffffff;
	for(int i = 0 ; i < 10 ; ++i){
		if(howmany[i] < 3){
			howmany[i]++;
			for(int i = 0 ; i < switches[who].size() ; ++i){
				int target = switches[who][i];
				pan[target] = forward(pan[target]);
			}					
			tmp_min = min(solve(i, idx + 1) + 1, tmp_min);
			howmany[i]--;
			for(int i = 0 ; i < switches[who].size() ; ++i){
				int target = switches[who][i];
				pan[target] = prev(pan[target]);
			}			
		}
	}	
	return ret = tmp_min;
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
		memset(howmany, 0, sizeof(howmany));
		memset(cache, -1, sizeof(cache));
		for(int i = 0 ; i < 16 ; ++i){
			scanf("%d", &pan[i]);
		}
		
		if(check()){
			printf("0\n");
			continue;
		}
		
		int ans = 0x7fffffff;
		for(int i = 0 ; i < 10 ; ++i){
			for(int j = 0 ; j < switches[i].size() ; ++j){
				int target = switches[i][j];
				pan[target] = forward(pan[target]);
			}			
			howmany[i]++;
			ans = min(ans, solve(i, 0) + 1);
			howmany[i]--;	
			for(int j = 0 ; j < switches[i].size() ; ++j){
				int target = switches[i][j];
				pan[target] = prev(pan[target]);
			}		
		}

		if(ans < 0)	ans = -1;
		printf("%d\n", ans);
	}
	
	return 0;
}
