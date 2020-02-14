// 각 test case에 대해 두 소수 사이의 변환에 필요한 최소 회수를 출력한다. 불가능한 경우 Impossible을 출력한다.

#include <stdio.h>
#include <queue>
#include <cmath>
#include <string.h>

using namespace std;

struct INFO{
	int num, len;
};

int T;
int src, dst;

queue<INFO> q;

int visited[10000];

bool check(int test){
	int sq = (int)sqrt(test);
	for(int i = 2 ; i <= sq ; ++i){
		if(test % i == 0)	return false;
	}
	return true;
}

int bfs(){
	
	while(!q.empty()){
		INFO now = q.front();	q.pop();
		int cur = now.num;
		
		if(cur == dst){
			return now.len;
		}
		
		int tmp = cur;
		int thousand = tmp / 1000;
		tmp -= (thousand * 1000);
		int hundred = tmp / 100;
		tmp -= (hundred * 100);
		int ten = tmp / 10;
		tmp -= (ten * 10);
		int one = tmp;
		
		// 1000의 자리 
		for(int i = 1 ; i <= 9 ; ++i){
			if(i == thousand)	continue;
			int a = cur - (thousand * 1000) + (i * 1000);
			if(!check(a) || visited[a] != 0)	continue;
			INFO next;
			next.num = a;	next.len = now.len + 1;
			visited[a] = 1;
			q.push(next);
		}
		
		// 100의 자리 
		for(int i = 0 ; i <= 9 ; ++i){
			if(i == hundred)	continue;
			int a = cur - (hundred * 100) + (i * 100);
			if(!check(a) || visited[a] != 0)	continue;
			INFO next;
			next.num = a;	next.len = now.len + 1;
			visited[a] = 1;
			q.push(next);
		}
		
		// 10의 자리 
		for(int i = 0 ; i <= 9 ; ++i){
			if(i == ten)	continue;
			int a = cur - (ten * 10) + (i * 10);
			if(!check(a) || visited[a] != 0)	continue;
			INFO next;
			next.num = a;	next.len = now.len + 1;
			visited[a] = 1;
			q.push(next);
		}
		
		// 1의 자리 
		for(int i = 0 ; i <= 9 ; ++i){
			if(i == one)	continue;
			int a = cur - (one) + (i);
			if(!check(a) || visited[a] != 0)	continue;
			INFO next;
			next.num = a;	next.len = now.len + 1;
			visited[a] = 1;
			q.push(next);
		}
	}
	return -1;
}
 
int solve(int a, int b){
	INFO start;
	start.num = a;	start.len = 0;
	visited[a] = 1;
	q.push(start);
	
	return bfs();
}

int main(){
	scanf("%d", &T);
	
	for(int z = 0 ; z < T ; ++z){
		memset(visited, 0, sizeof(visited));
		while(!q.empty())	q.pop();
		scanf("%d %d", &src, &dst);	
		int ans = solve(src, dst);
		if(ans == -1){
			printf("Impossible\n");
			return 0;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
