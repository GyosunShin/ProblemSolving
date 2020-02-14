// K(2≤K≤5)
// V(1≤V≤20,000)와 간선의 개수 E(1≤E≤200,000)
// 1 ~ V 

#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

struct INFO{
	int idx, color;
};

int T;

vector<int> vs[200001];
int visited[200001];

bool ans;

queue<INFO> q;

void bfs(){
	
	while(!q.empty()){
		if(!ans)	break;
		INFO cur = q.front();	q.pop();
		for(int i = 0 ; i < vs[cur.idx].size() ; ++i){
			int next_idx = vs[cur.idx][i];

			if(visited[next_idx] != -1 && visited[next_idx] == cur.color){
				ans = false;
				break;	
			}
			if(visited[next_idx] != -1 && visited[next_idx] != cur.color){
				continue;
			}
			if(visited[next_idx] == -1){
				INFO next;
				next.idx = next_idx;	next.color = (cur.color + 1)%2;
				visited[next_idx] = next.color;
				q.push(next);
			}
		}
	}
	
}

int main(){
	scanf("%d", &T);
	for(int t = 0 ; t < T ; ++t){
		memset(visited, -1, sizeof(visited));
		ans = true;
		int V, E;
		scanf("%d %d", &V, &E);
		for(int i = 0 ; i <= V ; ++i)	vs[i].clear();
		for(int i = 0 ; i < E ; ++i){
			int tmp1, tmp2;
			scanf("%d %d", &tmp1, &tmp2);
			vs[tmp1].push_back(tmp2);	vs[tmp2].push_back(tmp1);
		}
		//#######################################################
		
		bool tmp_ans = true;
		for(int i = 1 ; i <= V ; ++i){
			if(visited[i] == -1){
				INFO tmp;
				tmp.idx = i;	tmp.color = 0;
				q.push(tmp);
				bfs();
				if(!ans){
					tmp_ans = false;
					break;
				}
				while(!q.empty())	q.pop();
			}
		}
		while(!q.empty())	q.pop();
		if(tmp_ans)	printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}
