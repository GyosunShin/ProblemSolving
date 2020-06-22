// 손님 Pick 우선순위
// 1st) 택시 현재 위치에서 가장 가까운 승객 
// 2nd) 행 번호가 가장 작은 승객
// 3rd) 열 번호가 가장 작은 승객

// INPUT
// 2 ≤ N ≤ 20		 1 ≤ M ≤ N^2		 1 ≤ 초기 연료 ≤ 500,000

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct GUEST{
	int sr, sc, er, ec;
	int dis;
	bool alive;
};

GUEST guests[400];

int N, M, K;
int pan[20][20];
bool visited[20][20];
int start_r, start_c;

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

queue<pair<int, pair<int, int>>> q;

vector<pair<pair<int, int>, pair<int, int>>> v;

bool comp(pair<pair<int, int>, pair<int, int>>& a, pair<pair<int, int>, pair<int, int>>& b){
	if(a.first.first == b.first.first && a.second.first == b.second.first)	return a.second.second < b.second.second;
	if(a.first.first == b.first.first)	return a.second.first < b.second.first;
	return a.first.first < b.first.first;
}

bool rangeCheck(int r, int c){
	if(0 > r || r >= N || 0 > c || c >= N)	return false;
	return true;
}

int disCal(int sr, int sc, int er, int ec){
	memset(visited, false, sizeof(visited));
	while(!q.empty())	q.pop();
	
	visited[sr][sc] = true;
	q.push(make_pair(0, make_pair(sr, sc)));
	
	int ret = 0;
	
	while(!q.empty()){
		int cur_r = q.front().second.first;	int cur_c = q.front().second.second;
		int sofar = q.front().first;	q.pop();
		
		if(cur_r == er && cur_c == ec)	return sofar;
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			int next_sofar = sofar + 1;
			if(!rangeCheck(next_r, next_c))	continue;
			if(pan[next_r][next_c] == 1 || visited[next_r][next_c])	continue;
			
			visited[next_r][next_c] = true;
			q.push(make_pair(next_sofar, make_pair(next_r, next_c)));
		}
	}
	
	return 0x7fffffff;
}

int solve(){
	
	while(true){
		
		// 택시 위치 ~~ 각 승객의 위치 dis 계산
		for(int i = 0 ; i < M ; ++i){
			guests[i].dis = disCal(start_r, start_c, guests[i].sr, guests[i].sc);
		}
		
		v.clear();
		for(int i = 0 ; i < M ; ++i){
			if(guests[i].alive){
				v.push_back(make_pair(make_pair(guests[i].dis, i), make_pair(guests[i].sr, guests[i].sc)));
			}
		}
		
		if(v.empty())	return K;
		
		sort(v.begin(), v.end(), comp);
		
		int targetIdx = v[0].first.second;
		int howlong = v[0].first.first;
		guests[targetIdx].alive = false;
		
		// 모실 승객으로 이동 
		K -= howlong;
		if(K < 0)	return -1;
		
		// 승객 태우고 목적지까지 이동시작
		int take = disCal(guests[targetIdx].sr, guests[targetIdx].sc, guests[targetIdx].er, guests[targetIdx].ec);
		K -= take;
		if(K < 0)	return -1;
		
		// 목적지 도착 후, 연료 충전 
		K += (take * 2);
		
		// 택시 현재 위치 갱신
		start_r = guests[targetIdx].er;	start_c = guests[targetIdx].ec;
	}
	
}

int main(){
	scanf("%d %d %d", &N, &M, &K);
	
	// (0 : 빈칸) 	(1 : 벽)
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &pan[i][j]);
		}
	}
	
	// 택시 초기 위치
	scanf("%d %d", &start_r, &start_c);
	start_r--; 	start_c--;
	
	// 각 승객의 출발지의 행과 열 번호, 그리고 목적지의 행과 열 번호
	for(int i = 0 ; i < M ; ++i){
		scanf("%d %d %d %d", &guests[i].sr, &guests[i].sc, &guests[i].er, &guests[i].ec);
		guests[i].sr--;	guests[i].sc--;	guests[i].er--;	guests[i].ec--;
		guests[i].alive = true;
	}
	
	int ret = solve();
	
	// OUTPUT
	// 모든 손님을 이동시키고 연료를 충전했을 때 남은 연료의 양을 출력한다
	// 단, 이동 도중에 연료가 바닥나서 다음 출발지나 목적지로 이동할 수 없으면 -1을 출력
	// 모든 손님을 이동시킬 수 없는 경우에도 -1을 출력한다.
	printf("%d", ret);
	
	return 0;
}
