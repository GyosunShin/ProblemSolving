// 0 <= n <= 9999
// d1 d2 d3 d4

// D : 2배한다. 2배한 값이 10000이상이면 % 10000 
// S : -1하는데 -1한게 0되면 9999로!
// L : d2 d3 d4 d1 
// R : d4 d1 d2 d3 

// OUTPUT : A에서 B로 변환하기 위해 필요한 최소한의 명령어 나열을 출력한다.

#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct INFO{
	string track;
	int num;
};

int T, src, dst;
int visited[10000];

queue<INFO> q;

void bfs(){
	
	while(!q.empty()){
		
		INFO cur = q.front();	q.pop();
		if(cur.num == dst){
			cout << cur.track << endl;
			return;
		}
		
		int tmp;
		// D
		tmp = (cur.num * 2) % 10000;
		if(visited[tmp] == 0){
			INFO next;
			next.num = tmp;
			next.track = cur.track + "D";
			visited[tmp] = 1;
			q.push(next); 
		}
		
		// S
		tmp = (cur.num);
		if(tmp == 0)	tmp = 9999;
		else	tmp = (cur.num - 1);
		if(visited[tmp] == 0){
			INFO next;
			next.num = tmp;
			next.track = cur.track + "S";
			visited[tmp] = 1;
			q.push(next); 
		}
		
		int ttmp = cur.num;
		int thousand = ttmp / 1000;
		ttmp -= (thousand * 1000);
		int hundred = ttmp / 100;
		ttmp -= (hundred * 100);
		int ten = ttmp / 10;
		ttmp -= (ten * 10);
		int one = ttmp;
		
		// L
		tmp = (cur.num % 1000) * 10 + (cur.num / 1000);
		if(visited[tmp] == 0){
			INFO next;
			next.num = tmp;
			next.track = cur.track + "L";
			visited[tmp] = 1;
			q.push(next); 
		}
		
		// R
		tmp = (cur.num % 10) * 1000 + (cur.num / 10);
		if(visited[tmp] == 0){
			INFO next;
			next.num = tmp;
			next.track = cur.track + "R";
			visited[tmp] = 1;
			q.push(next); 
		}
	}
	
}

void solve(int a, int b){
	INFO start;
	start.num = a;
	visited[a] = 1;
	q.push(start);
	bfs();
}

int main(){
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		memset(visited, 0, sizeof(visited));
		while(!q.empty())	q.pop();
		scanf("%d %d", &src, &dst);	
		solve(src, dst);
	}
	return 0;
}
