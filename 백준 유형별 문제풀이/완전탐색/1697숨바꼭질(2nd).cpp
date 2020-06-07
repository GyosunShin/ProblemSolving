// (0 ¡Â N ¡Â 100,000) 

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;
bool visited[100001];

queue<pair<int, int>> q;

int main(){
	scanf("%d %d", &N, &K);
	
	q.push({N, 0});
	visited[N] = true;
	
	while(!q.empty()){
		int cur = q.front().first;	int time = q.front().second;
//			printf("CUr : %d\n", cur);
		q.pop();
		
		if(cur == K){
			printf("%d", time);
			return 0;
		}
		
		for(int i = 0 ; i < 3; ++i){
			int next;
			if(i == 0){
				next = cur + 1;
			}
			else if(i == 1){
				next = cur - 1;
			}
			else if(i == 2){
				next = cur * 2;
			}
			
			if(next < 0 || next > 100000 || visited[next])	continue;
			visited[next] = true;
			q.push({next, time+1});
		}
		
	}
	
	return 0;
}
