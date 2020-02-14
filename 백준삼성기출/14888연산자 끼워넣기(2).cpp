// 수의 개수 N(2 ≤ N ≤ 11)
// A1, A2, ..., AN (1 ≤ Ai ≤ 100)
// 셋째 줄에는 합이 N-1인 4개의 정수가 주어지는데, 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수

// OUTPUT : 최대 \n 최소 

#include <stdio.h>
#include <vector>

using namespace std;
 
int N;
int map[11];
int opers[4]; // + - * /

int mmin = 0x7fffffff;
int mmax = -1 * mmin;

vector<int> v;


void dfs(){
	if(v.size() == N-1){
		printf("[");
		for(int i = 0 ; i < v.size() ; ++i){
			printf("%d ", v[i]);
		}
		printf("]\n\n");
		int tmp_ret = map[0];
		for(int i = 1 ; i < N ; ++i){
			if(v[i-1] == 0){  // +
				tmp_ret += map[i];
			}
			else if(v[i-1] == 1){  // -
				tmp_ret -= map[i];
			}
			else if(v[i-1] == 2){  // *
				tmp_ret *= map[i];
			}
			else if(v[i-1] == 3){  // /
				tmp_ret /= map[i];
			}									
		}
		
		if(tmp_ret > mmax)	mmax = tmp_ret;
		if(tmp_ret < mmin)	mmin = tmp_ret;
		return;
	}
	
	for(int i = 0 ; i < 4 ; ++i){
		if(opers[i] > 0){
			--opers[i];
			v.push_back(i);
			dfs();
			++opers[i];
			v.pop_back();
		}
	}
	
	
}

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);
	}
	for(int i = 0 ; i < 4 ; ++i){
		scanf("%d", &opers[i]);
	}
	//###############################
	
	
	dfs();
	printf("%d\n%d", mmax, mmin);
	return 0;
}


