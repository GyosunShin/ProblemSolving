// 이닝 수 N(2 ≤ N ≤ 50)

//안타: 1
//2루타: 2
//3루타: 3
//홈런: 4
//아웃: 0

// OUTPUT : 아인타팀이 얻을 수 있는 최대 점수를 출력한다.

// !! 아인타는 자신이 가장 좋아하는 선수인 1번 선수를 4번 타자로 미리 결정했다 !!

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int pan[50][9];
bool used[9];

vector<int> picked;

int ans = 0;

int simulate(){
	
	int sum = 0;
	int idx = 0;
	
	for(int i = 0 ; i < N ; ++i){
//		printf("이닝 %d\n", i);
		
		int out = 0;
		vector<int> runner;
		
		while(true){
			if(out >= 3)	break;
			
			int cur = pan[i][picked[idx]];
			
			if(cur == 0)	out++;
			else if(1 <= cur && cur <= 3){
				for(int j = 0 ; j < runner.size() ; ++j){
					if(runner[j] == -1)	continue;
					runner[j] += cur;
					if(runner[j] >= 4){
						sum++;
						runner[j] = -1;
					}
				}
				runner.push_back(cur);
			}
			else if(cur == 4){
				for(int j = 0 ; j < runner.size() ; ++j){
					if(runner[j] != -1)	sum++;
				}
				sum++;
				runner.clear();
			}
			
			idx++;
			if(idx >= 9)	idx = 0;
		}
	}
	
	return sum;
}

void dfs(){
	
	if(picked.size() == 9){
		
//		for(int i = 0 ; i < picked.size() ; ++i)	printf("%d ", picked[i]);
//		printf("\n");

		if(picked[3] != 0)	return;
		
		int ret = simulate();
		
//		printf("RET : %d\n\n", ret);
		
		ans = max(ans, ret);
		
		return;
	}
	
	
	for(int i = 0 ; i < 9 ; ++i){
		if(!used[i]){
			used[i] = true;
			picked.push_back(i);
			dfs();
			used[i] = false;
			picked.pop_back();
		}
	}
	
}

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < 9 ; ++j){
			scanf("%d", &pan[i][j]);		
		}
	}
	
	dfs();
	printf("%d", ans);
	
	return 0;
}
