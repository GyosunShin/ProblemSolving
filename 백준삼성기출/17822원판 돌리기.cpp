// 2 ≤ N, M ≤ 50    1 ≤ T ≤ 50
// 2 ≤ xi ≤ N
// 0 ≤ di ≤ 1
// 1 ≤ ki < M

// d  --> (0 : 시계방향) (1 : 반시계방향)

//인접하면서 수가 같은 것을 모두 찾는다.
//  --> 그러한 수가 있는 경우에는 원판에서 인접하면서 같은 수를 모두 지운다.
//  --> 없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.

#include <cstdio> 
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO{
	int r, c, cnt;
};

queue<INFO> q;

int N, M, T;
int map[51][51];
bool visited[51][51];
int x, d, k;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

void clockwise(){
	// x의 배수인 원판을
	// k칸 회전!
	
	for(int i = x ; i <= N ; i += x){
		for(int z = 0 ; z < k ; ++z){
			int tmp = map[i][M];
			for(int j = M-1 ; j >= 1 ; --j){
				map[i][j+1] = map[i][j];
			}
			map[i][1] = tmp;
		}
	}
}

void unclock(){
	// x의 배수인 원판을
	// k칸 회전!
	
	for(int i = x ; i <= N ; i += x){
		for(int z = 0 ; z < k ; ++z){
			int tmp = map[i][1];
			for(int j = 2 ; j <= M ; ++j){
				map[i][j-1] = map[i][j];
			}
			map[i][M] = tmp;
		}
	}
}

bool bfs(int start_r, int start_c){
	vector<pair<int, int> > picked;
	INFO start;
	start.r = start_r;	start.c = start_c;	start.cnt = 0;
	visited[start_r][start_c] = true;
	q.push(start);
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		picked.push_back(make_pair(cur.r, cur.c));
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
			if(next_c == 0)	next_c = M;
			if(next_c == M+1)	next_c = 1;
			if(0 >= next_r || next_r > N || visited[next_r][next_c] || map[next_r][next_c] != map[cur.r][cur.c])	continue;
			visited[next_r][next_c] = true;
			INFO next;
			next.r = next_r;	next.c = next_c;	next.cnt = cur.cnt + 1;
			q.push(next);
		}
	}	
	
//	printf("START_R : %d  / START_C : %d / PICKED_SIZE : %d \n",start_r, start_c , picked.size());
	
	if(picked.size() == 1)	return false;
	
	for(int i = 0 ; i < picked.size() ; ++i){
		map[picked[i].first][picked[i].second] = -1;
	}
	picked.clear();
	return true;
}

int main(){
	memset(map, -1, sizeof(map));
	
	scanf("%d %d %d", &N, &M, &T);
	
	for(int i = 1 ; i <= N ; ++i){
		for(int j = 1 ; j <= M ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	for(int q = 0 ; q < T ; ++q){
		scanf("%d %d %d", &x, &d, &k);
		// 번호가 xi의 배수인 원판을 di방향으로 ki칸 회전시킨다. di가 0인 경우는 시계 방향, 1인 경우는 반시계 방향이다.
		// // d  --> (0 : 시계방향) / (1 : 반시계방향)
		if(d == 0)	clockwise();
		else if(d == 1)	unclock();
		
//		printf("AFTER ROTATE! \n");
//		for(int i = 1 ; i <= N ; ++i){
//			for(int j = 1 ; j <= M ; ++j){
//				printf("%d  ", map[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
		
		//인접하면서 수가 같은 것을 모두 찾는다.
		//  --> 그러한 수가 있는 경우에는 원판에서 인접하면서 같은 수를 모두 지운다.
		//  --> 없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.
		
		bool flag = true;
		for(int i = 1 ; i <= N ; ++i){
			for(int j = 1 ; j <= M ; ++j){	
				if(map[i][j] != -1){
					memset(visited, false, sizeof(visited));
					if(bfs(i, j))	flag = false;
				}
			}
		}
		
		if(flag){
			float avg = 0;
			float cnt = 0;
			for(int i = 1 ; i <= N ; ++i){
				for(int j = 1 ; j <= M ; ++j){
					if(map[i][j] != -1){
						avg += map[i][j];
						++cnt;
					}
				}
			}
			if(cnt > 0){
				avg = avg / cnt;
				for(int i = 1 ; i <= N ; ++i){
					for(int j = 1 ; j <= M ; ++j){
						if(map[i][j] != -1){
							if(map[i][j] > avg)	map[i][j]--;
							else if(map[i][j] < avg)	map[i][j]++;
						}
					}	
				}
			}
			if(cnt == 0)	break;
		}
		
//		printf("DUPLICAE CHECK!! \n");
//		for(int i = 1 ; i <= N ; ++i){
//			for(int j = 1 ; j <= M ; ++j){
//				printf("%d  ", map[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
	}
	
	
	
	int ans = 0;
	// 원판을 T번 회전시킨 후 원판에 적힌 수의 합을 구해보자.
	for(int i = 1 ; i <= N ; ++i){
		for(int j = 1 ; j <= M ; ++j){
			if(map[i][j] != -1)	ans += map[i][j];
		}
	}
	printf("%d", ans);
	
	return 0;
}

