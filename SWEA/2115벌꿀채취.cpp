// N(3 �� N �� 10), M(1 �� M �� 5), C(10 �� C �� 30)


// OUTPUT : �̶� �� �ϲ��� ���� ä���Ͽ� ���� �� �ִ� ������ ���� �ִ밡 �Ǵ� ��츦 ã��, 
// �� ���� �ִ� ������ ����ϴ� ���α׷��� �ۼ��϶�.

#include <stdio.h> 
#include <string.h>
#include <vector>
#include <algorithm> 

using namespace std;

int T, N, M, C;
int map[10][10];
int cache[10][10];

vector<pair<int, int> > picked;
vector<pair<int, int> > otherpicked;

int real_ans = -1 * 0x7fffffff;

int picked_indexing(int ind, int sum, int res){	  // picked ���Ϳ� ��� index��ġ�� �̿� 
    if(sum > C) return 0;
    if(ind == M) return res;
    
    int add = map[picked[ind].first][picked[ind].second] * map[picked[ind].first][picked[ind].second];
    return max(picked_indexing(ind+1, sum+map[picked[ind].first][picked[ind].second], res+add),
	picked_indexing(ind+1, sum, res));
}
int other_indexing(int ind, int sum, int res){	  // otherpicked ���Ϳ� ��� index��ġ�� �̿� 
    if(sum > C) return 0;
    if(ind == M) return res;
    
    int add = map[otherpicked[ind].first][otherpicked[ind].second] * map[otherpicked[ind].first][otherpicked[ind].second];
    return max(other_indexing(ind+1, sum+map[otherpicked[ind].first][otherpicked[ind].second], res+add),
	other_indexing(ind+1, sum, res));
}
	

void otherdfs(int start_r, int start_c){
	if(otherpicked.size() == M){
		int ret1 = picked_indexing(0, 0, 0);
		int ret2 = other_indexing(0, 0, 0);
		int sum = ret1 + ret2;
		if(real_ans < sum)	real_ans = sum;
		return;
	}
	
	for(int i = start_r ; i < N ; ++i){
		for(int j = start_c ; j < N ; ++j){
			if(j + (M-1) >= N)	continue;
			bool tmp_flag = false;
			for(int k = 0 ; k < M ; ++k){
				if(cache[i][j + k] != -1){
					tmp_flag = true;
					break;
				}
			}			
			if(tmp_flag)	continue;
			for(int k = 0 ; k < M ; ++k){
				otherpicked.push_back(pair<int, int>(i, j + k));	
				cache[i][j + k] = 1;
			}
			if(j + (M-1) == N-1)	otherdfs(i+1, 0);
			else	otherdfs(i, j+M);
			for(int k = 0 ; k < M ; ++k){
				otherpicked.pop_back();
				cache[i][j + k] = -1;
			}			
		}
		start_c = 0;
	}	
}

void dfs(int start_r, int start_c){
	if(picked.size() == M){
		memset(cache, -1, sizeof(cache));
		for(int i = 0 ; i < picked.size() ; ++i){
			cache[picked[i].first][picked[i].second] = 1;
		}
		otherdfs(0,0);
		return;
	}
	
	for(int i = start_r ; i < N ; ++i){
		for(int j = start_c ; j < N ; ++j){
			if(j + (M-1) >= N)	continue;
			bool tmp_flag = false;
			for(int k = 0 ; k < M ; ++k){
				if(cache[i][j + k] != -1){
					tmp_flag = true;
					break;
				}
			}
			if(tmp_flag)	continue;
			for(int k = 0 ; k < M ; ++k){
				//########################################
				picked.push_back(pair<int, int>(i, j + k));	
				//########################################
				cache[i][j + k] = 1;
			}
			if(j + (M-1) == N-1)	dfs(i+1, 0);
			else	dfs(i, j+M);
			for(int k = 0 ; k < M ; ++k){
				picked.pop_back();
				cache[i][j + k] = -1;
			}
		}
		start_c = 0;	
	}
	
}

int main(){
	scanf("%d", &T);
	for(int z = 1 ; z <= T ; ++z){
		memset(cache, -1, sizeof(cache));
		real_ans = -1 * 0x7fffffff;
		scanf("%d %d %d", &N, &M, &C);	
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &map[i][j]);
			}
		}
		//###################################
		
		dfs(0, 0);
		
		printf("#%d %d\n", z, real_ans);
	}
	
	return 0;
}
