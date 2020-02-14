// 2 <= 순열의 크기 N <= 8
// K

// OUTPUT : 첫째 줄에 정답을 출력한다. 만약 오름차순으로 만들 수 없으면 -1을 출력한다.

#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <set> 
#include <string>

using namespace std;

struct INFO{
	int map[8];
	int cnt;
};

queue<INFO> q;

int N, K;
int map[8];
set<string> visited;

bool check(int (&arr)[8]){
	
	for(int i = 0 ; i < N-1 ; ++i){
		if(arr[i] > arr[i+1]){
			return false;
		}
	}
	
	return true;
}

void rev(int (&arr)[8], int start){
	int cnt = K-1;
	for(int i = start ; i <= (start + (start + K - 1))/2 ; ++i){
		swap(arr[i], arr[i+cnt]);
		cnt -= 2;
	}
}

int bfs(){
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		
//		printf("CUR : %d\n", cur.cnt);
//		for(int i = 0 ; i < N ; ++i)	printf("%d  ", cur.map[i]);
//		printf("\n\n");
		
		if(check(cur.map)){
			return cur.cnt;
		}
	
		for(int i = 0 ; (i + K) <= N ; ++i){
			INFO next;
			int tmp[8];
			copy(cur.map, cur.map + N, tmp);
			rev(tmp, i);
			
			string str;
			for(int j = 0 ; j < N ; ++j){
				str += to_string(tmp[j]);
			}
//			cout << "SHIT : " << str << endl;
			set<string>::iterator it;
			it = visited.find(str);
			if(it != visited.end()){
				continue;
			}
			visited.insert(str);
			copy(tmp, tmp + N, next.map);
			next.cnt = cur.cnt + 1;
			q.push(next);
		}
	}
	return -1;
}

int main(){
	scanf("%d %d", &N, &K);
	getchar();
	string str;
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);
		str += to_string(map[i]);
	}
	visited.insert(str);
	INFO start;
	copy(map, map+N, start.map);
	start.cnt = 0;
	q.push(start);
	
	printf("%d", bfs());	
	
	return 0;
}
