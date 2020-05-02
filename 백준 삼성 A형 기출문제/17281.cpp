// �̴� �� N(2 �� N �� 50)

//��Ÿ: 1
//2��Ÿ: 2
//3��Ÿ: 3
//Ȩ��: 4
//�ƿ�: 0

// OUTPUT : ����Ÿ���� ���� �� �ִ� �ִ� ������ ����Ѵ�.

// !! ����Ÿ�� �ڽ��� ���� �����ϴ� ������ 1�� ������ 4�� Ÿ�ڷ� �̸� �����ߴ� !!

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
//		printf("�̴� %d\n", i);
		
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
