// 2 <= 순열의 크기 N <= 8
// K

// OUTPUT : 첫째 줄에 정답을 출력한다. 만약 오름차순으로 만들 수 없으면 -1을 출력한다.

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO{
	int map[8];
	int cnt;
};

queue<INFO> q;

int N, K;
int map[8];

bool check(int (&arr)[8]){
	bool ret = true;
	
	for(int i = 0 ; i < N-1 ; ++i){
		if(arr[i] > arr[i+1]){
			ret = false;
			break;
		}
	}
	
	return ret;
}

void rev(int (&arr)[8], int start){
	int cnt = K-1;
	for(int i = start ; i < (start + K)/2 ; ++i){
		swap(arr[i], arr[i+cnt]);
		cnt -= 2;
	}
}

int bfs(){
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		
//		for(int i = 0 ; i < N ; ++i)	printf("%d  ", cur.map[i]);
//		printf("\n");
		
		if(check(cur.map)){
			return cur.cnt;
		}
	
		for(int i = 0 ; (i + K) <= N ; ++i){
			INFO next;
			int tmp[8];
			copy(cur.map, cur.map + N, tmp);
			rev(tmp, i);
			copy(tmp, tmp + N, next.map);
			next.cnt = cur.cnt + 1;
			q.push(next);
		}
	}
	return -1;
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);
	}
	
	INFO start;
	copy(map, map+N, start.map);
	start.cnt = 0;
	q.push(start);
	
	printf("%d", bfs());
	
	return 0;
}
// 25분 구현 --> 메모리 초과 
