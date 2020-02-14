// 약품 투입 횟수를 최소로 하여 성능검사를 통과할 수 있는 방법
// 약품 투입 횟수를 출력

// (3≤D≤13)  R
// (1≤W≤20)  C
// 합격기준 (1≤K≤D)

#include <stdio.h> 
#include <vector>

using namespace std;

int T;
int R, C, K;
int map[13][20];

vector<int> picked;
vector<char> abpicked;

int ans = 0x7fffffff; 

bool escap = false;

bool solve(){
	// Solve With picked, abpicked VECTORs!
	int backup[13][20];
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			backup[i][j] = map[i][j];
		}
	}
	
	for(int i = 0 ; i < picked.size() ; ++i){
		int tmp;
		if(abpicked[i] == 'A')	tmp = 0;
		else if(abpicked[i] == 'B')	tmp = 1;
		for(int j = 0 ; j < C ; ++j){
			backup[picked[i]][j] = tmp;
		}
	}
	
//	for(int i = 0 ; i < R ; ++i){
//		for(int j = 0 ; j < C ; ++j){
//			printf("%d ", backup[i][j]);
//		}
//		printf("\n");
//	}
	
	
	// 이제 K기준 부합하는지 검사!
	for(int i = 0 ; i < C ; ++i){
		int start = backup[0][i];
		int tmp_cnt = 1;
		int tmp_ans = -1 * 0x7fffffff;
		for(int j = 1 ; j < R ; ++j){
			if(start == backup[j][i]){
				++tmp_cnt;
			}
			else{
				if(tmp_ans < tmp_cnt)	tmp_ans = tmp_cnt;
				start = backup[j][i];
				tmp_cnt = 1;
			}
			
			if(j == R-1){
				if(tmp_ans < tmp_cnt)	tmp_ans = tmp_cnt;
			}
		}
		if(tmp_ans < K){
//			printf("FALSE\n");
			return false;
		}
	}
//	printf("CORRETCT\n");
	escap = true;
	ans = picked.size();
	return true;
}

void check(int cnt){
	if(escap) return;
	if(abpicked.size() == cnt){
//		for(int i = 0 ; i < abpicked.size() ; ++i)	printf("%c ", abpicked[i]);
//		printf("\n");				
		if(solve()){  // K기준에 부합하는 경우임 
			if(ans > cnt)	ans = cnt;
		}
		return;
	}
	
	for(int i = 0 ; i < 2 ; ++i){
		if(i == 0)	abpicked.push_back('A');
		else	abpicked.push_back('B');
		check(cnt);
		abpicked.pop_back();
	}
	
}

void dfs(int cnt, int start){
	if(escap) return;
	if(picked.size() == cnt){
//		printf("CNT : %d\n", cnt);
//		for(int i = 0 ; i < picked.size() ; ++i)	printf("%d ", picked[i]);
//		printf("\n");
		check(cnt);
		
		return;
	}
	
	for(int i = start ; i < R ; ++i){
		picked.push_back(i);
		dfs(cnt, i + 1);
		picked.pop_back();
	}
}

int main(){
	scanf("%d", &T);
	for(int z = 1 ; z <= T ; ++z){
		escap = false;
		ans = 0x7fffffff; 
		// D W K
		scanf("%d %d %d", &R, &C, &K);	 
		if(K==1){
			printf("#%d 0\n", z);
			continue;
		}	
		// A : 0    /     B : 1
		for(int i = 0 ; i < R; ++ i){
			for(int j = 0 ; j < C ; ++j){
				scanf("%d", &map[i][j]);
			}
		}		//#########################################
		
		
		for(int i = 0 ; i <= K ; ++i){   // 0개 ~ K개 선택가능하도록 
			if(escap) break;
			dfs(i, 0);
		}
		
		printf("#%d %d\n", z, ans);
	}
	
	return 0;
}

