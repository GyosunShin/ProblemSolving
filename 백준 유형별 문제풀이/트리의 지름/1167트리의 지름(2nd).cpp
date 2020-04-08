// 정점의 개수 V가 주어지고 (2≤V≤100,000)

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<pair<int, int>> tree[100001];
bool visited[100001];

int far, mmax;

void dfs(int start, int sofar){
	
	if(mmax < sofar){
		mmax = sofar;
		far = start;
	}
	
	for(int i = 0 ; i < tree[start].size() ; ++i){
		int next = tree[start][i].first;
		if(!visited[next]){
			visited[next] = true;
			dfs(next, sofar + tree[start][i].second);
			visited[next] = false;
		}
		
	}
	
}

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		int src;
		scanf("%d", &src);	
		while(true){
			int dst;
			scanf("%d", &dst);
			if(dst == -1)	break;
			else{
				int weight;
				scanf("%d", &weight);	
				tree[src].push_back({dst, weight});
			}
		}
	}
	
	visited[1] = true;
	dfs(1, 0);
	visited[1] = false;	
	
	visited[far] = true;
	dfs(far, 0);
	visited[far] = false;	
	
	printf("%d", mmax);
	
	return 0;
}




