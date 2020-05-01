// 도시의 개수 N <= 200
// M <= 1000

#include <cstdio> 
#include <cstring>

int N, M;

int parent[200];
int rank[200];

int find(int u){
	if(parent[u] == u)	return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v){
	
	u = find(u);	v = find(v);
	
	if(u == v)	return;
	
	if(rank[u] > rank[v]){
		parent[v] = u;
	}
	else{
		parent[u] = v;
		if(rank[u] == rank[v]){
			rank[v]++;
		}
	}
	
}

int main(){
	
	for(int i = 0 ; i < 200 ; ++i){
		parent[i] = i;
		rank[i] = 1;
	}
	
	scanf("%d", &N);
	scanf("%d", &M);
	
	int tmp;
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			// (1 연결)  (0 비연결)
			scanf("%d", &tmp);
			if(tmp == 1){
				merge(i, j);
			}
		}
	}
	int start;
	for(int i = 0 ; i < M ; ++i){
		scanf("%d", &tmp);
		tmp--;
		if(i == 0){
			start = find(tmp);
			continue;
		}
		if(start != find(tmp)){
			printf("NO");
			return 0;		
		}
	}
	
	printf("YES");
	return 0;	
}



