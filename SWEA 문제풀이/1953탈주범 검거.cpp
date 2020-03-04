// 탈주범이 있을 수 있는 위치의 개수를 계산

// (5 ≤ N(R), M(C) ≤ 50) 
// (1 ≤ L ≤ 20)

// 1 ~ 7은 해당 위치의 터널 구조물 타입 / (0 : 빈칸)

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int T, R, C, start_r, start_c, L;
int pan[50][50];
bool visited[50][50];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0 ,0, -1, 1};

int ans;

bool check[4][4] = {
	{false, true, false, false},
	{true, false, false, false},
	{false, false, false, true},
	{false, false, true, false}
};

vector<int> type[8] = {
	vector<int>(0),
	vector<int>({0,1,2,3}),
	vector<int>({0,1}),
	vector<int>({2,3}),
	vector<int>({0,3}),
	vector<int>({1,3}),
	vector<int>({2,1}),
	vector<int>({0,2}),
};

queue<pair<pair<int, int>, int > > q;

void bfs(){
	visited[start_r][start_c] = true;
	q.push(make_pair(make_pair(start_r, start_c), 1));
	
	while(!q.empty()){
		int cur_r = q.front().first.first;	int cur_c = q.front().first.second;
		int cur_time = q.front().second;
		q.pop();
//		printf("CUR_R : %d/ CUR_C :%d / CUR_TIME : %d\n", cur_r, cur_c, cur_time);
		
		if(cur_time > L)	return;
		
		++ans;
		
		for(int i = 0 ; i < type[pan[cur_r][cur_c]].size() ; ++i){
			int next_r = cur_r + dr[type[pan[cur_r][cur_c]][i]];	int next_c = cur_c + dc[type[pan[cur_r][cur_c]][i]];
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C || visited[next_r][next_c]
			|| !(1 <= pan[next_r][next_c] && pan[next_r][next_c] <= 7))	continue;
				
			bool tmp_flag = false;
			for(int j = 0 ; j < type[pan[next_r][next_c]].size() ; ++j){
				if(check[type[pan[next_r][next_c]][j]][type[pan[cur_r][cur_c]][i]]){
					tmp_flag = true;
					break;
				}
			}
			if(!tmp_flag)	continue;
				
			visited[next_r][next_c] = true;
//			printf("[next] (%d, %d) %d\n", next_r, next_c, cur_time + 1);
			q.push(make_pair(make_pair(next_r, next_c), cur_time + 1));
		}
		
	}
	
}

int main(){
	
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		while(!q.empty())	q.pop();
		ans = 0;
		memset(visited, false, sizeof(visited));
		scanf("%d %d %d %d %d", &R, &C, &start_r, &start_c, &L);	
		for(int i = 0 ; i < R ; ++i){
			for(int j = 0 ; j < C ; ++j){
				scanf("%d", &pan[i][j]);
			}
		}
		
		bfs();
		
		printf("#%d %d\n", z, ans);
	}
	return 0;
	
}


