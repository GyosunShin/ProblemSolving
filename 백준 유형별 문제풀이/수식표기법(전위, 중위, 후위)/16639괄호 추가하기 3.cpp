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

int answer = -1 * 0x7fffffff;

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
	for(int i = 0 ; i < N ; ++i)	cache[i] = -1 * 0x7fffffff;
	
	for(int i = 0 ; i < picked.size() ; ++i){
		
		int cur_idx = picked[i];
		int tmp_ret = 0;
		
		if(cache[cur_idx-1] != -1 * 0x7fffffff && cache[cur_idx+1] != -1 * 0x7fffffff){
			tmp_ret = oper(cache[cur_idx-1], cache[cur_idx+1], cur_idx);
		}
		else if(cache[cur_idx-1] != -1 * 0x7fffffff && cache[cur_idx+1] == -1 * 0x7fffffff){
			tmp_ret = oper(cache[cur_idx-1], pan[cur_idx+1] - '0', cur_idx);
		}
		else if(cache[cur_idx-1] == -1 * 0x7fffffff && cache[cur_idx+1] != -1 * 0x7fffffff){
			tmp_ret = oper(pan[cur_idx-1] - '0', cache[cur_idx+1], cur_idx);
		}
		else if(cache[cur_idx-1] == -1 * 0x7fffffff && cache[cur_idx+1] == -1 * 0x7fffffff){
			tmp_ret = oper(pan[cur_idx-1] - '0', pan[cur_idx+1] - '0', cur_idx);
		}
		
		cache[cur_idx] = tmp_ret;	cache[cur_idx+1] = tmp_ret;	cache[cur_idx-1] = tmp_ret;
		for(int j = cur_idx-1 ; j >= 0 ; --j){
			if(cache[j] == -1 * 0x7fffffff)	break;
			cache[j] = tmp_ret;
		}
		for(int j = cur_idx+1 ; j < N ; ++j){
			if(cache[j] == -1 * 0x7fffffff)	break;
			cache[j] = tmp_ret;
		}
		
	}
	
//	printf("RET : %d\n", cache[0]);
	return cache[0];
	
}


void dfs(){
	
	if((int)picked.size() == (N/2)){
		answer = max(answer, check());
		return;
	}
	
	for(int i = 1 ; i <= (N-2) ; i = i+2){
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
	for(int i = 0 ; i < N ; ++i)	cache[i] = -1 * 0x7fffffff;
	getchar();
	for(int i = 0 ; i < N ; ++i)	scanf("%1c", &pan[i]);
	
	if(N == 1){
		printf("%d", pan[0] - '0');
		return 0;
	}

	// Operator의 개수 = N/2
	// 1 ~ 3 ~~~~ (N-2)
	dfs();
	printf("%d", answer);
	
	return 0;
}
