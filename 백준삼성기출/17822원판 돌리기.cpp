// 2 �� N, M �� 50    1 �� T �� 50
// 2 �� xi �� N
// 0 �� di �� 1
// 1 �� ki < M

// d  --> (0 : �ð����) (1 : �ݽð����)

//�����ϸ鼭 ���� ���� ���� ��� ã�´�.
//  --> �׷��� ���� �ִ� ��쿡�� ���ǿ��� �����ϸ鼭 ���� ���� ��� �����.
//  --> ���� ��쿡�� ���ǿ� ���� ���� ����� ���ϰ�, ��պ��� ū ������ 1�� ����, ���� ������ 1�� ���Ѵ�.

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
	// x�� ����� ������
	// kĭ ȸ��!
	
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
	// x�� ����� ������
	// kĭ ȸ��!
	
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
		// ��ȣ�� xi�� ����� ������ di�������� kiĭ ȸ����Ų��. di�� 0�� ���� �ð� ����, 1�� ���� �ݽð� �����̴�.
		// // d  --> (0 : �ð����) / (1 : �ݽð����)
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
		
		//�����ϸ鼭 ���� ���� ���� ��� ã�´�.
		//  --> �׷��� ���� �ִ� ��쿡�� ���ǿ��� �����ϸ鼭 ���� ���� ��� �����.
		//  --> ���� ��쿡�� ���ǿ� ���� ���� ����� ���ϰ�, ��պ��� ū ������ 1�� ����, ���� ������ 1�� ���Ѵ�.
		
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
	// ������ T�� ȸ����Ų �� ���ǿ� ���� ���� ���� ���غ���.
	for(int i = 1 ; i <= N ; ++i){
		for(int j = 1 ; j <= M ; ++j){
			if(map[i][j] != -1)	ans += map[i][j];
		}
	}
	printf("%d", ans);
	
	return 0;
}

