// ��ǰ�� �������� �ʰ� ���ɰ˻縦 ����ϴ� ��쿡�� 0�� ����Ѵ�.

// ��ȣ�ʸ� �β� (3��D��13)
// ��ȣ�ʸ� ���� (1��W��20)
// �հݱ��� (1��K��D)

// OUTPUT : ���ɰ˻縦 ����� �� �ִ� ��ǰ�� �ּ� ���� Ƚ��
 
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int T, D, W, K; 
int pan[13][20];
int backup[13][20];

vector<int> row_picked;
vector<int> color_picked;

int global_cnt;

int ans;
bool global_break = false;

vector<vector<int>> zerone;
vector<int> tmp;

bool check2(){
	for(int i = 0 ; i < W ; ++i){   // C
		bool ret = false;
		for(int j = 0 ; j <= D-K ; ++j){    // R
			bool tmp_ret = true;
			int avg = pan[j][i];
			for(int k = 1 ; k < K ; ++k){   // �ٸ��� �ϳ��� ������ break 
				if(pan[j+k][i] != avg){
					tmp_ret = false;
					break;
				}
			}
			if(tmp_ret){   // �����ΰ� �ϳ��� �ִ°�� 
				ret = true;
				break; 
				
			}
		}
		if(!ret){   // �� ���̶� �������ϸ� ������ 
			return false; 
		}
		
	}
	return true;
}

bool check(){
	for(int i = 0 ; i < W ; ++i){   // C
		bool ret = false;
		for(int j = 0 ; j <= D-K ; ++j){    // R
			bool tmp_ret = true;
			int avg = backup[j][i];
			for(int k = 1 ; k < K ; ++k){   // �ٸ��� �ϳ��� ������ break 
				if(backup[j+k][i] != avg){
					tmp_ret = false;
					break;
				}
			}
			if(tmp_ret){   // �����ΰ� �ϳ��� �ִ°�� 
				ret = true;
				break; 
			}
		}
		if(!ret){   // �� ���̶� �������ϸ� ������ 
			return false; 
		}
		
	}
	return true;
}


void row_change(int idx, int forwhat){
	for(int i = 0 ; i < W ; ++i){
		backup[idx][i] = forwhat;
	}
}

void dfs(int start){
	if(global_break){
		return;
	}	
	
	if(row_picked.size() == global_cnt){
		// ������ �ߺ����� �̿� 
		for(int i = 0 ; i < zerone.size() ; ++i){
			copy(&pan[0][0], &pan[0][0] + 13 * 20, &backup[0][0]);
			for(int j = 0 ; j < zerone[i].size() ; ++j){
				int cur_color = zerone[i][j];
				int cur = row_picked[j];	
				row_change(cur, cur_color);	
			}
			
			if(check()){
				global_break = true;
				return;
			}
			
		}
		return;	
	}
	
	for(int i = start ; i < D ; ++i){
		row_picked.push_back(i);
		dfs(i+1);
		row_picked.pop_back();
	}
}


bool solve(int cnt){   // D�� �߿��� cnt�� ���� ��
	
	global_cnt = cnt;
	
	// D C global_cnt
	dfs(0);
	
	if(global_break){
		ans = cnt;
		return true;
	}	
	
	return false;
}

void ddfs(int cnt){
	
	if(tmp.size() == cnt){
		zerone.push_back(tmp);
		return;
	}
	
	for(int i = 0 ; i < 2; ++i){
		tmp.push_back(i);
		ddfs(cnt);
		tmp.pop_back();
	}
	
}

int main(){
	scanf("%d", &T);
	for(int z = 1 ; z <= T ; ++z){
		// �β� D, ����ũ�� W, �հݱ��� K
		global_break = false;
		scanf("%d %d %d", &D, &W, &K);			
		for(int i = 0 ; i < D ; ++i){
			for(int j = 0 ; j < W ; ++j){
				scanf("%d", &pan[i][j]);	// (A : 0) (B : 1)
			}
		}
		
		if(check2()){
			printf("#%d %d\n", z, 0);
		}
		else{
			// (D C 1)	(D C 2)	(D C 3)
			for(int i = 1 ; i <= D ; ++i){
//				printf("[%d]\n", i);

				zerone.clear();
				ddfs(i);
				
//				printf("[%d]\n", i);
//				for(int i = 0 ; i < zerone.size() ; ++i){
//					for(int j = 0 ; j < zerone[i].size() ; ++j){
//						printf("%d ", zerone[i][j]);
//					}
//					printf("\n");
//				}
//				printf("\n");
				
				if(solve(i))	break;
				
			}
			printf("#%d %d\n", z, ans);
		}
		
	}	
	
	return 0;
}
