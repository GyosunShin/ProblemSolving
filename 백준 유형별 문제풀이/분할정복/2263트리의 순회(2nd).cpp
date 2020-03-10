// (1≤n≤100,000)

// OUTPUT : PRE순서 출력 

#include <cstdio>

int N;
int in[100000];
int post[100000];
int idxes[100001];

void solve(int in_start, int in_end, int post_start, int post_end){
	if(post_start > post_end)	return;
	
	printf("%d ", post[post_end]);
//	if(post_end == post_start)	return;
	
	int idx = idxes[post[post_end]];
	int howmany = idx - in_start;
	
	solve(in_start, idx-1, post_start, post_start+howmany-1);
	solve(idx+1, in_end, post_start+howmany, post_end-1);
	
}

int main(){
	
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &in[i]);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &post[i]);
	for(int i = 0 ; i < N ; ++i)	idxes[in[i]] = i;
	
	solve(0, N-1, 0, N-1);
	
	return 0;
	
}
