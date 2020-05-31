// 사건의 개수 n(400 이하의 자연수)		전후 관계의 개수 k(50,000 이하의 자연수)

// 사건의 전후 관계를 알고 싶은 사건 쌍의 수 s(50,000 이하의 자연수)

// OUTPUT
// (모르면 : 0)  (맞았으면 : -1) (틀렸으면 : 1)

#include <cstdio> 
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, S;
int cache[401][401];
bool visited[401];

vector<int> graph[401];

int start;

void dfs(int idx){
	cache[start][idx] = -1;
	
	for(int i = 0 ; i < graph[idx].size() ; ++i){
		int next = graph[idx][i];
		if(!visited[next]){
			visited[next] = true;
			dfs(next);
		}
	}
}

void solve(){
	
	for(int i = 1 ; i <= N ; ++i){
		memset(visited, false, sizeof(visited));
		start = i;
		dfs(i);
	}
	
}

int main(){
	memset(cache, 0, sizeof(cache));
	scanf("%d %d", &N, &K);
	
	int a, b;
	for(int i = 0 ; i < K ; ++i){
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
	}
	
	solve();
	
	scanf("%d", &S);
	for(int i = 0 ; i < S ; ++i){
		scanf("%d %d", &a, &b);		
		if(cache[b][a] == -1)	printf("1\n");
		else	printf("%d\n", cache[a][b]);
	}
	
	return 0;
}
