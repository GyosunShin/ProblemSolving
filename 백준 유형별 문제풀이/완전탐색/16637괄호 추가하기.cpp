// 괄호를 적절히 추가해 만들 수 있는 식의 결과의 최댓값을 구하는 프로그램을 작성
// 1 ≤ N(수식의 길이) ≤ 19
// + - *

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N;
char pan[19];
int cache[19];
bool used[19];

vector<int> picked;

int answer = -1;

int oper(int left, int right, int idx){
	int ret = 0;
	
	if(pan[idx] == '+'){
		ret = left + right;
	}
	else if(pan[idx] == '-'){
		ret = left - right;
	}
	else if(pan[idx] == '*'){
		ret = left * right;
	}
	
	return ret;
}

int check(){
	memset(cache, -1, sizeof(cache));
	
	for(int i = 0 ; i < picked.size() ; ++i){
		printf("%d ", picked[i]);
	}
	printf("\n");
	
	for(int i = 0 ; i < picked.size() ; ++i){
		
//		for(int j = 0 ; j < N ; ++j){
//			printf("%d ", cache[j]);
//		}
//		printf("\n");				
		
		int cur_idx = picked[i];
		int tmp_ret = 0;
		
		if(cache[cur_idx-1] != -1 && cache[cur_idx+1] != -1){
			tmp_ret = oper(cache[cur_idx-1], cache[cur_idx+1], cur_idx);
		}
		else if(cache[cur_idx-1] != -1 && cache[cur_idx+1] == -1){
			tmp_ret = oper(cache[cur_idx-1], pan[cur_idx+1] - '0', cur_idx);
		}
		else if(cache[cur_idx-1] == -1 && cache[cur_idx+1] != -1){
			tmp_ret = oper(pan[cur_idx-1] - '0', cache[cur_idx+1], cur_idx);
		}
		else if(cache[cur_idx-1] == -1 && cache[cur_idx+1] == -1){
			tmp_ret = oper(pan[cur_idx-1] - '0', pan[cur_idx+1] - '0', cur_idx);
		}
		
		cache[cur_idx] = tmp_ret;	cache[cur_idx+1] = tmp_ret;	cache[cur_idx-1] = tmp_ret;
		for(int j = cur_idx-1 ; j >= 0 ; --j){
			if(cache[j] == -1)	break;
			cache[j] = tmp_ret;
		}
		for(int j = cur_idx+1 ; j < N ; ++j){
			if(cache[j] == -1)	break;
			cache[j] = tmp_ret;
		}
		
	}
	
	printf("RET : %d\n", cache[0]);
	return cache[0];
	
}

bool doubly_check(int i){
	
	if(i == 1){
		
		
		
	}
	else if(i == N-2){
		
	}
	else{
		
		
		
	}
	
}

void dfs(){
	
	if((int)picked.size() == (N/2)){
		answer = max(answer, check());
		return;
	}
	
	for(int i = 1 ; i <= (N-2) ; i = i+2){
		if(!used[i] && doubly_check(i)){
			used[i] = true;
			picked.push_back(i);
			dfs();
			used[i] = false;
			picked.pop_back();
		}
	}
	
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	getchar();
	for(int i = 0 ; i < N ; ++i)	scanf("%1c", &pan[i]);
	
	// Operator의 개수 = N/2
	// 1 ~ 3 ~~~~ (N-2)
	dfs();
	printf("%d", answer);
	
	return 0;
}
