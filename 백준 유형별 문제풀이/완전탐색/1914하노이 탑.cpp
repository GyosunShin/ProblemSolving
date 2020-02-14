// INPUT : 첫 번째 장대에 쌓인 원판의 개수 N (1 ≤ N ≤ 100)이 주어진다.

// OUTPUT : 이 작업을 수행하는데 필요한 이동 순서를 출력하는 프로그램을 작성하라. 단, 이동 횟수는 최소가 되어야 한다.

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO{
	vector<pair<int, int> > track;
	vector<int> a;
	vector<int> b;
	vector<int> c;
	int time;
};

queue<INFO> q;

int N;

void bfs(){
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		if((cur.a.size() == 0) && (cur.b.size() == 0) && (cur.c.size() == N)){
			printf("%d\n", cur.time);
			if(N >= 20){
				return;
			}
			for(int i = 0 ; i < cur.track.size() ; ++i){
				printf("%d %d\n", cur.track[i].first, cur.track[i].second);
			}
			return;
		}
		
		// 1 --> 2
		if(cur.a.size() != 0){
			INFO next;
			next = cur;
			int a = next.a.back();
			if(next.b.size() == 0){
				next.a.pop_back();
				next.b.push_back(a);
				next.time = cur.time + 1;
				next.track.push_back(make_pair(1,2));
				q.push(next);
			}
			else{
				int b = next.b.back();	
				if(a < b){
					next.a.pop_back();
					next.b.push_back(a);	
					next.time = cur.time + 1;
					next.track.push_back(make_pair(1,2));
					q.push(next);
				}
			}
		}		
		
		// 1 --> 3
		if(cur.a.size() != 0){
			INFO next;
			next = cur;
			int a = next.a.back();
			if(next.c.size() == 0){
				next.a.pop_back();
				next.c.push_back(a);
				next.time = cur.time + 1;
				next.track.push_back(make_pair(1,3));
				q.push(next);
			}
			else{
				int c = next.c.back();	
				if(a < c){
					next.a.pop_back();
					next.c.push_back(a);	
					next.time = cur.time + 1;
					next.track.push_back(make_pair(1,3));
					q.push(next);
				}
			}
			
		}		
		
		// 2 --> 3
		if(cur.b.size() != 0){
			INFO next;
			next = cur;
			int b = next.b.back();
			if(next.c.size() == 0){
				next.b.pop_back();
				next.c.push_back(b);
				next.time = cur.time + 1;
				next.track.push_back(make_pair(2,3));
				q.push(next);
			}
			else{
				int c = next.c.back();	
				if(b < c){
					next.b.pop_back();
					next.c.push_back(b);	
					next.time = cur.time + 1;
					next.track.push_back(make_pair(2,3));
					q.push(next);
				}
			}
			
		}		
		
		// 2 --> 1
		if(cur.b.size() != 0){
			INFO next;
			next = cur;
			int b = next.b.back();
			if(next.a.size() == 0){
				next.b.pop_back();
				next.a.push_back(b);
				next.time = cur.time + 1;
				next.track.push_back(make_pair(2,1));
				q.push(next);
			}
			else{
				int a = next.a.back();	
				if(b < a){
					next.b.pop_back();
					next.a.push_back(b);	
					next.time = cur.time + 1;
					next.track.push_back(make_pair(2,1));
					q.push(next);
				}
			}
		}		
		
		// 3 --> 2
		if(cur.c.size() != 0){
			INFO next;
			next = cur;
			int c = next.c.back();
			if(next.b.size() == 0){
				next.c.pop_back();
				next.b.push_back(c);
				next.time = cur.time + 1;
				next.track.push_back(make_pair(3,2));
				q.push(next);
			}
			else{
				int b = next.b.back();	
				if(c < b){
					next.c.pop_back();
					next.b.push_back(c);	
					next.time = cur.time + 1;
					next.track.push_back(make_pair(3,2));
					q.push(next);
				}
			}
			
		}		
		
		// 3 --> 1
		if(cur.c.size() != 0){
			INFO next;
			next = cur;
			int c = next.c.back();
			if(next.a.size() == 0){
				next.c.pop_back();
				next.a.push_back(c);
				next.time = cur.time + 1;
				next.track.push_back(make_pair(3,1));
				q.push(next);
			}
			else{
				int a = next.a.back();	
				if(c < a){
					next.c.pop_back();
					next.a.push_back(c);	
					next.time = cur.time + 1;
					next.track.push_back(make_pair(3,1));
					q.push(next);
				}
			}
		}		
	}
}

int main(){
	scanf("%d", &N);
	
	INFO start;
	for(int i = N ; i > 0 ; --i){
		start.a.push_back(i);	
	}
	start.time = 0;
	q.push(start);
	
	bfs();
	
	return 0;
}
 
