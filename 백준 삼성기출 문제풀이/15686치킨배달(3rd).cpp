// (0 빈칸) (1 집) (2 치킨집)

// N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 13

// 첫째 줄에 폐업시키지 않을 치킨집을 최대 M개를 골랐을 때, 도시의 치킨 거리의 최솟값을 출력한다.

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO{
	int r, c, dis;
};

int N, M;
int map[50][50];
bool visited[50][50];

vector<pair<int, int> > zips;
vector<pair<int, int> > cs;
vector<int> picked;

int chickens;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int ans = 0x7fffffff;

//int bfs(int start_r, int start_c){
//	memset(visited, false, sizeof(visited));
//	INFO start;
//	start.r = start_r;	start.c = start_c;	start.dis = 0;
//	queue<INFO> q;
//	visited[start_r][start_c] = true;
//	q.push(start);
//	
//	while(!q.empty()){
//		INFO cur = q.front();	q.pop();
//		
//		if(map[cur.r][cur.c] == 2){
//			return cur.dis;
//		}
//		
//		for(int dir = 0 ; dir < 4 ; ++dir){
//			int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
//			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N || visited[next_r][next_c])	continue;
//			visited[next_r][next_c] = true;
//			INFO next;
//			next.r = next_r;	next.c = next_c;	next.dis = cur.dis + 1;
//			q.push(next);
//		}	
//	}
//}

int check(int home_r, int home_c){
	
	int ret = 0x7fffffff;
	for(int i = 0 ; i < cs.size() ; ++i){
		if(map[cs[i].first][cs[i].second] != 2)	continue;
		int tmp = abs(cs[i].first - home_r) + abs(cs[i].second - home_c);
		ret = min(ret, tmp);
	}
	return ret;
	
}

void dfs(int start){
	
	if(picked.size() == M){
		
		for(int i = 0 ; i < picked.size() ; ++i){
			map[cs[picked[i]].first][cs[picked[i]].second] = 0;
		}
		
		int tmp_sum = 0;
		
		for(int i = 0 ; i < zips.size() ; ++i){		
			int start_r = zips[i].first;	int start_c = zips[i].second;
			tmp_sum += check(start_r, start_c);
		}		
		
		ans = min(tmp_sum, ans);
		
		for(int i = 0 ; i < picked.size() ; ++i){
			map[cs[picked[i]].first][cs[picked[i]].second] = 2;
		}		
		return;
	}
	
	for(int i = start ; i < cs.size() ; ++i){
		picked.push_back(i);
		dfs(i+1);
		picked.pop_back();
	}
	
}

int main(){
	scanf("%d %d", &N, &M);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 1){
				zips.push_back(make_pair(i, j));
			}
			else if(map[i][j] == 2){
				cs.push_back(make_pair(i, j));
			}
		}
	}
	
	M = cs.size() - M;
	
	// 조합이용 : M개 치킨 집 선택
	dfs(0);
	
	printf("%d", ans);
	
	return 0;
}
