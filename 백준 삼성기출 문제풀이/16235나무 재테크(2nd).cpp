#include <stdio.h> 
#include <queue>
#include <algorithm>

using namespace std;

struct TREE{
	int y, x, age;
};

bool operator<(TREE a, TREE b){  // < : less operator인거 같음! 
	return (a.age > b.age);
}

priority_queue<TREE> pq[2];  // 나이가 어린 나무 부터 pop되어야 한다. 
int n, m, k;
int map[10][10];  // 남은 영양분 표시하는 듯 
int add[10][10];  // 

const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
	int cur = 0;
	int next;
	scanf("%d %d %d", &n, &m, &k);
	for(int y = 0 ; y < n ; ++y){
		for(int x = 0 ; x < n ; ++x){
			scanf("%d", &add[y][x]);
			map[y][x] = 5;
		}
	}
	
	for(int i = 0 ; i < m ; ++i){
		TREE tree;
		scanf("%d %d %d", &tree.y, &tree.x, &tree.age);
		--tree.y;	--tree.x;
		pq[cur].push(tree);
	}
	
	for(int i = 0 ; i < k ; ++i){  // k년 동안... 
		next = (cur + 1) % 2;  // 0 (or) 1
		
		queue<TREE> life_tree;
		queue<TREE> dead_tree;
		
		while(!pq[cur].empty()){
			TREE cur_tree = pq[cur].top();	pq[cur].pop();
			
			if(map[cur_tree.y][cur_tree.x] >= cur_tree.age){   // "봄" : 어린 나무의 나이보다 적게 있으면 죽여 
				map[cur_tree.y][cur_tree.x] -= cur_tree.age;
				TREE next_tree;
				next_tree.y = cur_tree.y;
				next_tree.x = cur_tree.x;
				next_tree.age = cur_tree.age + 1;  // 자기 나이만큼 양분먹은다음 나이 ++1 되는 부분 
				
				life_tree.push(next_tree);  // 살아남은 나무 집어넣는 queue 
				pq[next].push(next_tree);   // 내년 나무 Priority Queue에 집어넣는다. 
			}
			else{   // 죽어야 되는 케이스 
				dead_tree.push(cur_tree);
			}
		}
		
		while(!dead_tree.empty()){   // "여름" 해당 케이스 : 죽은 나무 나이의 1/2에 해당하는 양분을 뒈진 자리에 ++..... 
			TREE cur_tree = dead_tree.front();	dead_tree.pop();
			map[cur_tree.y][cur_tree.x] += cur_tree.age / 2;
		}
		
		while(!life_tree.empty()){  // "가을" : 번식 --> 나이가 5의 배수인 나무인 경우 주변 8자리에 나이 1인 나무 심어주자! 
			TREE cur_tree = life_tree.front();	
			life_tree.pop();
			if(cur_tree.age % 5 == 0){  // 번식가능한 나무 
				for(int dir = 0 ; dir < 8 ; ++dir){
					TREE next_tree;
					next_tree.y = cur_tree.y + dy[dir];
					next_tree.x = cur_tree.x + dx[dir];
					next_tree.age = 1;
					
					// 밑에처럼 범위 고려는 항상 해줘야 하는 것이다! 
					if(next_tree.y < 0 || next_tree.y >= n || next_tree.x < 0 || next_tree.x >= n){
						continue;
					}
					
					pq[next].push(next_tree);
				}
			}
		}
		
		for(int y = 0 ; y < n ; ++y){   // "겨울" : 걍 각 땅덩어리에 양분 더해주셈! 
			for(int x = 0 ; x < n ; ++x){
				map[y][x] += add[y][x];	
			}
		}
		
		cur = next;
		
	}  // The End of k년 지난 후! 
	
	
	printf("%d\n", pq[next].size());
	return 0;
}
	
