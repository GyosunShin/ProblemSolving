// OUTPUT : K년이 지난 후 상도의 땅에 살아있는 나무의 개수

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K;
int A[10][10];
int pan[10][10];

priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, 
greater<pair<int, pair<int, int> > > > pq[2];

queue<pair<int, pair<int, int> > > death;

const int dr[] = {-1, 1, 0 ,0, -1, -1, 1, 1};
const int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

int year;

void ss(){	
	year %= 2;
	int next_year = (year + 1) % 2;
	int ttmp_cnt = 0;
	// 봄
	while(!pq[year].empty()){
		int cur_r = pq[year].top().second.first;	int cur_c = pq[year].top().second.second;	int age = pq[year].top().first;
		
		pq[year].pop();
		if(pan[cur_r][cur_c] < age){
			death.push(make_pair(age/2, make_pair(cur_r, cur_c)));
			continue;
		}

		ttmp_cnt++;
		pan[cur_r][cur_c] -= age;
		pq[next_year].push(make_pair(age+1, make_pair(cur_r, cur_c)));
	}
	
	// 여름
	while(!death.empty()){
		int cur_r = death.front().second.first;	int cur_c = death.front().second.second;	int howmany = death.front().first;
		death.pop();
		pan[cur_r][cur_c] += howmany;
	}
//	printf("[SS] pq[year %d]_SIZE : %d / pq[NEXT %d]_SIZE : %d\n",
//	year, pq[year].size(), next_year, pq[next_year].size());
	
	year = next_year;
	
}

void fw(){
	
	int next_year = (year + 1) % 2;
	
//	printf("[FW] pq[year %d]_SIZE : %d / pq[NEXT %d]_SIZE : %d\n",
//	year, pq[year].size(), next_year, pq[next_year].size());

	int tmp_cnt = 0;
	
	// 번식
	while(!pq[year].empty()){
		int cur_r = pq[year].top().second.first;	int cur_c = pq[year].top().second.second;	int age = pq[year].top().first;
		pq[year].pop();
		
		pq[next_year].push(make_pair(age, make_pair(cur_r, cur_c)));
		
		if(age % 5 != 0){
			continue;
		}
		tmp_cnt++;
		for(int dir = 0 ; dir < 8 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			if(!(0 > next_r || next_r >= N || 0 > next_c || next_c >= N)){
				pq[next_year].push(make_pair(1, make_pair(next_r, next_c)));	
			}
		}
	}
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			pan[i][j] += A[i][j];
		}
	}
//	printf("[FW] pq[year %d]_SIZE : %d / pq[NEXT %d]_SIZE : %d\n",
//	year, pq[year].size(), next_year, pq[next_year].size());
	
	year = next_year;
	
}

void solve(){
	
	// 봄, 여름 
	ss();
	
	// 가을, 겨울 
	fw();
		
}

int main(){
	
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &A[i][j]);
			pan[i][j] = 5;
		}
	}
	int x, y, z;
	for(int i = 0 ; i < M ; ++i){
		scanf("%d %d %d", &x, &y, &z);
		pq[year].push(make_pair(z, make_pair(x-1,y-1)));
	}
	
	for(int z = 1 ; z <= K ; ++z){
		solve();
	}
	
	// ANS : 살아있는 나무의 개수
	int ans = pq[year].size();
	printf("%d", ans);
	
	return 0;
}


