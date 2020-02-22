// (1 ≤ N, M ≤ 1,000,000)

#include <cstdio>

int N, M;
int panA[1000000];
int panB[1000000];
int ans[1000000];

void solve(){	// For) 오름차순 
	
	int aIdx = 0;
	int bIdx = 0;
	int idx = 0;
	
	while(aIdx < N && bIdx < M){
		
		if(panA[aIdx] < panB[bIdx]){
			ans[idx] = panA[aIdx++];
		}
		else{
			ans[idx] = panB[bIdx++];
		}
		
		idx++;
	}
	
	if(aIdx < N){
		for(int i = aIdx ; i < N ; ++i)	ans[idx++] = panA[i];
	}
	else if(bIdx < M){
		for(int i = bIdx ; i < M ; ++i)	ans[idx++] = panB[i];
	}
	
}

int main(){
	scanf("%d %d", &N, &M);
	
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &panA[i]);
	}
	for(int i = 0 ; i < M ; ++i){
		scanf("%d", &panB[i]);
	}
	
	solve();
	
	for(int i = 0 ; i < N+M ; ++i){
		printf("%d ", ans[i]);
	}
	
	return 0;
}
