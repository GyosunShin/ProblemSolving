// BC의 정보와 사용자의 이동 궤적이 주어졌을 때, 모든 사용자가 충전한 양의 합의 최댓값을 구하는 프로그램을 작성하라.

// 지도 크기 <= 10
// 총 이동 시간 (20 <= M <= 100)
// BC의 개수 (1 ≤ A ≤ 8)

// BC의 개수 A는 1이상 8이하의 정수이다. (1 ≤ A ≤ 8)
// 사용자가 지도 밖으로 이동하는 경우는 없다.

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO{
	int r, c, sofar;
};

int T, M, A;
int mapA[100];
int mapB[100];
vector<int> pan[10][10];

int chargers[8];

//           가만히 / 상 / 우 / 하 / 좌
const int dr[] = {0, -1, 0, 1, 0};
const int dc[] = {0, 0, 1, 0, -1};

bool visited[10][10];

void bfs(int start_r, int start_c, int howfar, int power){
	queue<INFO> q;
	INFO start;	start.r = start_r;	start.c = start_c;	start.sofar = 0;
	visited[start_r][start_c] = true;
	q.push(start);
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		if(cur.sofar > howfar)	break;
		pan[cur.r][cur.c].push_back(power);
		
		for(int dir = 1 ; dir < 5 ; ++dir){
			int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
			if(0 > next_r || next_r >= 10 || 0 > next_c || next_c >= 10 || visited[next_r][next_c])	continue;
			visited[next_r][next_c] = true;
			INFO next;
			next.r = next_r;	next.c = next_c;	next.sofar = cur.sofar + 1;
			q.push(next);
		}
	}	
}

int solve(int ar, int ac, int br, int bc){
	
	int sizea = pan[ar][ac].size();
	int sizeb = pan[br][bc].size();
	
	if(sizea == 0 && sizeb == 0)	return 0;
	int ret = -1 * 0x7fffffff;
	if(sizea == 0 && sizeb > 0){
		for(int j = 0 ; j < sizeb ; ++j){
			ret = max(ret, chargers[pan[br][bc][j]]);
		}
		return ret;
	}
	if(sizea > 0 && sizeb == 0){
		for(int i = 0 ; i < sizea ; ++i){
			ret = max(ret, chargers[pan[ar][ac][i]]);
		}
		return ret;
	}
	
	for(int i = 0 ; i < sizea ; ++i){
		for(int j = 0 ; j < sizeb ; ++j){
			if(pan[ar][ac][i] == pan[br][bc][j]){
				ret = max(chargers[pan[ar][ac][i]], ret);
			}
			else{
				ret = max((chargers[pan[ar][ac][i]] + chargers[pan[br][bc][j]]), ret);
			}
			
		}
	}
	
	return ret;
}

int main(){
	scanf("%d", &T);
	for(int z = 1 ; z <= T ; ++z){
		
		for(int i = 0 ; i < 10 ; ++i){
			for(int j = 0 ; j < 10 ; ++j){
				pan[i][j].clear();
			}
		}
		
		scanf("%d %d", &M, &A);
		for(int i = 0 ; i < M ; ++i){
			scanf("%d", &mapA[i]);
		}
		for(int i = 0 ; i < M ; ++i){
			scanf("%d", &mapB[i]);
		}
		for(int i = 0 ; i < A ; ++i){
			// 좌표(X, Y), 충전 범위(C), 처리량(P)
			int x, y, c, p;
			scanf("%d %d %d %d", &x, &y, &c, &p);
			int R = y - 1;	int C = x - 1;
			
			memset(visited, false, sizeof(visited));
			bfs(R, C, c, i);
			chargers[i] = p;
		}
		
		int ans = 0;
		
		int start_a_r = 0;	int start_a_c = 0;
		int start_b_r = 9;	int start_b_c = 9;
		
		ans += solve(start_a_r, start_a_c, start_b_r, start_b_c);
		
		for(int i = 0 ; i < M ; ++i){
			start_a_r += dr[mapA[i]];	start_a_c += dc[mapA[i]];
			start_b_r += dr[mapB[i]];	start_b_c += dc[mapB[i]];
				
			ans += solve(start_a_r, start_a_c, start_b_r, start_b_c);
		}
		
		printf("#%d %d\n", z, ans);
	}
	
	return 0;
}
