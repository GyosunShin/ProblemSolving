// n(1��n��100,000)

#include <cstdio>

int N;
int in[100000];
int post[100000];
int idx[100001];

void solve(int in_start, int in_end, int post_start, int post_end){
	
	if(in_start > in_end || post_start > post_end)	return;
	
	int cur_root = post[post_end];
	printf("%d ", post[post_end]);
	
	// ����
	solve(in_start, idx[cur_root] - 1, post_start, post_start + (idx[cur_root] - in_start) - 1);

	// ������ 
	solve(idx[cur_root] + 1, in_end, post_start + (idx[cur_root] - in_start), post_end - 1);
	
}

int main(){
	scanf("%d", &N);
	
	// InOrder    (l P r)
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &in[i]);
	
	// PostOrder  (l r P)
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &post[i]);
	
	// InOrder�� Index ǥ�� 
	for(int i = 0 ; i < N ; ++i)	idx[in[i]] = i;
	
	solve(0, N-1, 0, N-1);
	
	return 0;
}
