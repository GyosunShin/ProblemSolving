// 7 ≤  N ≤ 12
// 1 ≤  코어 개수 ≤ 12

// ( 0 : 빈칸) (1 : 코어)

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
int pan[12][12];

int ans = 0x7fffffff;
int max_core = -1 * 0x7fffffff;

vector<pair<int, int>> cores;
vector<int> picked;

int ddo(int dir, int cores_idx){
	
	int cur_r = cores[cores_idx].first;	int cur_c = cores[cores_idx].second;
	int ret_cnt = 0;
	
	bool tmp_flag = true;
	
	if(dir == 0){
		if(pan[0][cur_c] == 1)	return false;
		
		for(int i = 0 ; i < cur_r ; ++i){
			if(pan[i][cur_c] != 0){
				tmp_flag = false;
				break;
			}
			else{
				pan[i][cur_c] = 2;
				ret_cnt++;
			}
		}
		
		if(!tmp_flag){
			for(int i = 0 ; i < ret_cnt ; ++i){
				pan[i][cur_c] = 0;
			}
			return 0;
		}
		
	}
	else if(dir == 1){
		if(pan[N-1][cur_c] == 1)	return false;
		
		for(int i = N-1 ; i > cur_r ; --i){
			if(pan[i][cur_c] != 0){
				tmp_flag = false;
				break;
			}
			else{
				pan[i][cur_c] = 2;
				ret_cnt++;
			}
		}
		
		if(!tmp_flag){
			for(int i = N-1 ; i > N-1-ret_cnt ; --i){
				pan[i][cur_c] = 0;
			}
			return 0;
		}		
		
		
	}
	else if(dir == 2){
		if(pan[cur_r][0] == 1)	return false;
		
		for(int i = 0 ; i < cur_c ; ++i){
			if(pan[cur_r][i] != 0){
				tmp_flag = false;
				break;
			}
			else{
				pan[cur_r][i] = 2;
				ret_cnt++;
			}
		}
		
		if(!tmp_flag){
			for(int i = 0 ; i < ret_cnt ; ++i){
				pan[cur_r][i] = 0;
			}
			return 0;
		}		
	}
	else if(dir == 3){
		if(pan[cur_r][N-1] == 1)	return false;
		
		for(int i = N-1 ; i > cur_c ; --i){
			if(pan[cur_r][i] != 0){
				tmp_flag = false;
				break;
			}
			else{
				pan[cur_r][i] = 2;
				ret_cnt++;
			}
		}
		
		if(!tmp_flag){
			for(int i = N-1 ; i > N-1-ret_cnt ; --i){
				pan[cur_r][i] = 0;
			}
			return 0;
		}				
	}	
		
	return ret_cnt;
}

void unddo(int dir, int cores_idx){
	
	int cur_r = cores[cores_idx].first;	int cur_c = cores[cores_idx].second;
	
	if(dir == 0){
		for(int i = cur_r-1 ; i >= 0 ; --i){
			pan[i][cur_c] = 0;	
		}
	}
	else if(dir == 1){
		for(int i = cur_r+1 ; i < N ; ++i){
			pan[i][cur_c] = 0;	
		}		
	}
	else if(dir == 2){
		for(int i = cur_c-1 ; i >= 0 ; --i){
			pan[cur_r][i] = 0;	
		}
	}
	else if(dir == 3){
		for(int i = cur_c+1 ; i < N ; ++i){
			pan[cur_r][i] = 0;	
		}
	}		
	
}

void dfs(int wire, int depth, int cnt){
	
//	printf("WIRE : %d / DEPTH : %d / CNT : %d\n", wire, depth,cnt);
//	for(int i = 0 ; i < picked.size() ; ++i)	printf("%d  ", picked[i]);
//	printf("\n");
	
	
//	for(int i = 0 ; i < N ; ++i){
//		for(int j = 0 ; j < N ; ++j){
//			printf("%d  ", pan[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
	
	// 최대한 많은 Core에 전원을 연결하였을 경우, 전선 길이의 합을 구하고자 한다.
	if(max_core < cnt){
//		printf("DEPTH : %d / WIRE : %d\n", depth, wire);
//		for(int i = 0 ; i < picked.size() ; ++i)	printf("%d  ", picked[i]);
//		printf("\n");
		
		ans = wire;
		max_core = cnt;
	}
	else if(max_core == cnt){
//		printf("<><>DEPTH : %d / WIRE : %d\n", depth, wire);
//		for(int i = 0 ; i < picked.size() ; ++i)	printf("%d  ", picked[i]);
//		printf("\n");
		
		ans = min(ans, wire);
	}
	
	if(depth >= cores.size())	return;
	
	for(int i = 0 ; i < 5 ; ++i){
		if(i == 4){
			picked.push_back(i);
			dfs(wire, depth + 1, cnt);
			picked.pop_back();
		}
		else{
			int tmp_ret = ddo(i, depth);
			if(tmp_ret > 0){
				picked.push_back(i);
				dfs(wire + tmp_ret, depth + 1, cnt + 1);
				unddo(i, depth);	
				picked.pop_back();
			}
		}
	}
	
}


int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		ans = 0x7fffffff;
		max_core = -1 * 0x7fffffff;
		cores.clear();
		scanf("%d", &N);	
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &pan[i][j]);	
				if(pan[i][j] == 1 && i != 0 && i != N-1 && 
				j != 0 && j != N-1)	cores.push_back({i, j});
			}
		}
		
		dfs(0, 0, 0);
		
		printf("#%d %d\n", z, ans);
	}
	
	return 0;
}
