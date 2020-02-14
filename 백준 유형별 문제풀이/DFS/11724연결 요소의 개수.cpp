// (1 �� N(����) �� 1,000, 0 �� M(����) �� N��(N-1)/2) 
//  (1 �� u, v �� N, u �� v)

// OUTPUT : ù° �ٿ� ���� ����� ������ ����Ѵ�.

#include <stdio.h> 
#include <vector>

using namespace std;

vector<int> map[1000];  // 0 ~ 999
int visited[1000];

int N, M;

int ans;

bool dfs(int start){
	if(visited[start] != 0){
		return false;	
	}
	
	visited[start] = 1;
	
	
	for(int i = 0 ; i < map[start].size() ; ++i){
		dfs(map[start][i]);
	}
	return true;
}

int main(){
	scanf("%d %d", &N , &M);
	for(int i = 0 ; i < M ; ++i){
		int u ,v;
		scanf("%d %d", &u, &v);
		map[u-1].push_back(v-1);
		map[v-1].push_back(u-1);
	}
	
	for(int i = 0 ; i < N ; ++i){
		bool tmp = dfs(i);
		if(tmp)	++ans;
	}
	
	printf("%d", ans);
	
	return 0;
}
