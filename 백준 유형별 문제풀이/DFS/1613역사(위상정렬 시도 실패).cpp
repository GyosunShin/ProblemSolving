// 사건의 개수 n(400 이하의 자연수)		전후 관계의 개수 k(50,000 이하의 자연수)

// 사건의 전후 관계를 알고 싶은 사건 쌍의 수 s(50,000 이하의 자연수)

// OUTPUT
// (모르면 : 0)  (맞았으면 : -1) (틀렸으면 : 1)

#include <cstdio> 
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, S;

int ans[401];
int inDegree[401];

vector<int> graph[401];

queue<pair<int, int>> q;

void solve(){
	
	for(int i = 1 ; i <= N ; ++i){
		if(inDegree[i] == 0){
			q.push(make_pair(i, 0));
		}
	}
	
	while(!q.empty()){
		int cur = q.front().first;	ans[cur] = q.front().second;
		q.pop();
		
		for(int i = 0 ; i < graph[cur].size() ; ++i){
			int next = graph[cur][i];
			inDegree[next]--;
			
			if(inDegree[next] == 0){
				q.push(make_pair(next, ans[cur] + 1));
			}
		}
	}
	
}

int check(int a, int b){
	
	if(ans[a] == -1 || ans[b] == -1)	return 0;
	
	int tmp = ans[a] - ans[b];
	if(tmp < 0)	return -1;
	return 1;
	
}

int main(){
	memset(ans, -1, sizeof(ans));
	memset(inDegree, -1, sizeof(inDegree));
	scanf("%d %d", &N, &K);
	
	int a, b;
	for(int i = 0 ; i < K ; ++i){
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		if(inDegree[a] == -1){
			inDegree[a] = 0;	
		}
		if(inDegree[b] == -1){
			inDegree[b] = 0;	
		}
		inDegree[b]++;
	}
	
	solve();
	
//	for(int i = 1 ; i <= N ; ++i){
//		printf("[%d] ", ans[i]);
//	}
//	printf("\n");
	
	scanf("%d", &S);
	for(int i = 0 ; i < S ; ++i){
		scanf("%d %d", &a, &b);		
		printf("%d\n", check(a, b));
	}
	
	return 0;
}
